// Estabelece a leituras das distâncias
int distanceLeftList[DISTANCE_ARRAY_LENGHT] = { 0 }; // Lista das distâncias lidas da esquerda
int distanceRightList[DISTANCE_ARRAY_LENGHT] = { 0 }; // Lista das distâncias lidas da direita
int distanceLeft = 0; 
int distanceRight = 0;
int minimumDistance = 50;

void distanceSensorsInit() {
  pinMode(DIST_SENSOR_SHARP_LEFT_PIN, INPUT);
  pinMode(DIST_SENSOR_SHARP_RIGHT_PIN, INPUT);
}

// Leitura da lista de distância
int returnAverageValue(int list[DISTANCE_ARRAY_LENGHT]) {
  int sum = 0;
  for (int i = 0; i < DISTANCE_ARRAY_LENGHT; i++) sum += list[i];
  return sum / DISTANCE_ARRAY_LENGHT; // Média da lista de distância
}

// Atualiza as distâncias reconhecidas pelo sensor
void updateAvgDistanceLists(int leftAnalogRead, int rightAnalogRead) {
  for (int i = 0; i < (DISTANCE_ARRAY_LENGHT - 1); i++) distanceLeftList[i] = distanceLeftList[i + 1];
  distanceLeftList[DISTANCE_ARRAY_LENGHT - 1] = leftAnalogRead; // Atualiza com o dado mais novo lido e retira a leitura mais antiga (sensor da esquerda)
  for (int i = 0; i < (DISTANCE_ARRAY_LENGHT - 1); i++) distanceRightList[i] = distanceRightList[i + 1];
  distanceRightList[DISTANCE_ARRAY_LENGHT - 1] = rightAnalogRead; // Atualiza com o dado mais novo lido e retira a leitura mais antiga (sensor da direita)
}

// Atualiza com as novas leituras e retorna a variável para ocorrer o que é esperado dado a programação
void readDistanceSensorsValues() {
  updateAvgDistanceLists(analogRead(DIST_SENSOR_SHARP_LEFT_PIN), analogRead(DIST_SENSOR_SHARP_RIGHT_PIN));
  distanceLeft = returnAverageValue(distanceLeftList);
  distanceRight = returnAverageValue(distanceRightList);
}

void distanceSensorsPrint() {
  Serial.print("Esquerda: " + (String)distanceLeft + "\tDireita: " + (String)distanceRight);
}