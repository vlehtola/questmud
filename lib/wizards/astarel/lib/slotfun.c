
/* ac slotit ja niiden kerroin */
valid_slot(str) {
  if(str=="head") { return 1; }
  if(str=="cloak") { return 1; }
  if(str=="arms") { return 1; }
  if(str=="hands") { return 1; }
  if(str=="torso") { return 4; }
  if(str=="legs") { return 2; }
  if(str=="feet") { return 1; }
}
average_ac_divider() {
  /* Return the sum of returns in query_ac_slot for average calculating */
  return 11;
}
