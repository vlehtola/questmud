cmd_goin(string str) {
object plr;
if(this_player() -> query_level() < 3) return 0;
  if(!str) {
    write("## Usage : Goin [name]\n");
  return 1;
}

plr = find_player(str);
if(!plr) {
  write("Can't find " + str + ".\n");
return 1;
}
if(this_player() -> query_level() < plr -> query_level()) {
  write("Can't goin to higher level wizards.\n");
  return 1;
}

 move_object(this_player(), plr);
write("Moving to " + str + "'s inventory.\n");
return 1;
}
