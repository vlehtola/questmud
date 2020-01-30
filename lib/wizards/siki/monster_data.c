get_hp(int level) {
  int hp,cost;
  cost = allocate(21);
  cost[0] = 0;  /* level 0 */
  cost[1] = 60;
  cost[2] = 400; /* level 10 */
  cost[3] = 700;
  cost[4] = 1600;
  cost[5] = 3100;
  cost[6] = 4600;
  cost[7] = 6100;
  cost[8] = 8100;
  cost[9] = 12000;
  cost[10] = 15000;
  cost[11] = 18000;
  cost[12] = 23000;
  cost[13] = 28000;
  cost[14] = 36000;  /* level 70 */
  cost[15] = 41000;
  cost[16] = 56000;
  cost[17] = 71000;
  cost[18] = 81000;
  cost[19] = 91000;
  cost[20] = 110000; /* level 100 */
  if(level/5 > 19) level = 99;
  hp = cost[level/5] + (cost[level/5+1] - cost[level/5]) *
         (level - (level/5*5)) /5;

  return hp;
}
