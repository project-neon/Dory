int distanceLeftList[DISTANCE_ARRAY_LENGHT] = { 0 };
int distanceRightList[DISTANCE_ARRAY_LENGHT] = { 0 };
int distanceLeft = 0;
int distanceRight = 0;
int minimumDistance = 20;

void distanceSensorsInit() {
  pinMode(DIST_SENSOR_SHARP_LEFT_PIN, INPUT);
  pinMode(DIST_SENSOR_SHARP_RIGHT_PIN, INPUT);
}

int returnListAvarageValue(int list[DISTANCE_ARRAY_LENGHT]) {
  int sum = 0;
  for (int i = 0; i < DISTANCE_ARRAY_LENGHT; i++) sum += list[i];
  return sum / DISTANCE_ARRAY_LENGHT;
}

void updateAvgDistanceLists(int leftAnalogRead, int rightAnalogRead) {
  for (int i = 0; i < (DISTANCE_ARRAY_LENGHT - 1); i++) distanceLeftList[i] = distanceLeftList[i + 1];
  distanceLeftList[DISTANCE_ARRAY_LENGHT - 1] = leftAnalogRead;
  for (int i = 0; i < (DISTANCE_ARRAY_LENGHT - 1); i++) distanceRightList[i] = distanceRightList[i + 1];
  distanceRightList[DISTANCE_ARRAY_LENGHT - 1] = rightAnalogRead;
}

void readDistanceSensorsValues() {
  updateAvgDistanceLists(analogRead(DIST_SENSOR_SHARP_LEFT_PIN), analogRead(DIST_SENSOR_SHARP_RIGHT_PIN));
  distanceLeft = returnListAvarageValue(distanceLeftList);
  distanceRight = returnListAvarageValue(distanceRightList);
}

void distanceSensorsPrint() {
  Serial.print("Esquerda: " + (String)distanceLeft + "\tDireita: " + (String)distanceRight);
}