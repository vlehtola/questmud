inherit "room/room";


reset(arg) {

  short_desc = "Falling down";
  long_desc = "You are falling down to you death!!!\n";
  
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}

kuolema(delay, ob) {
	call_out("loppu",delay,ob);
}

loppu(ob) { 
	if(!ob->query_wiz()) {
	 ob->death();
	} else {
	 tell_object(ob,"At this point, a mortal would be dead!\n");
	}
	return 1;
}