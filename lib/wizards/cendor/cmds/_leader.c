#define LEADER_D "/obj/leader_d"
cmd_leader(string str) {
  string fiu;
  if(!str) {
  write("Usage : leader [race]\n");
  return 1;
}
  str = lower_case(str);
  fiu = LEADER_D->query_leaderi(str);
if(!fiu) {
  write(capitalize(str) + " race does not have a leader.\n");
return 1;
}
 write("The leader of " + capitalize(str) + " race is " + capitalize(fiu) + ".\n");
 return 1;
}

