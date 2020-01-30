cmd_dice(int num) {
  int i, tmp;
  if(!num) {
     write("Usage: 'dice [number]'.\n");
     return 1;
  }
  if(!sscanf(num, "%d", tmp)) {
     write("Usage: 'dice [number]'.\n");
     return 1;
  }
  if (tmp < 2 || tmp > 1000) {
       write("Number can not be less than 2 or greater than 1000.\n");
	return 1;
  }
  i = random(tmp);
  i += 1;
write("You throw a "+tmp+" sided dice and get a "+i+".\n");
say(this_player()->query_name()+" throws a "+tmp+" sided dice and gets a "+ 
	i+".\n");
  return 1;
}

