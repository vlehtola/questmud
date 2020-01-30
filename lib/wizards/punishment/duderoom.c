inherit "room/room";

/* melko suorana ripattu esimerkistä ihan vaan rutiinin vuoksi */

reset(arg) {
        if(arg) return;        
  /* Laittaa kun jaksaa moiset, keppia tulee jos randomit */
  add_exit("postikusti","/world/city/inn");
  add_exit("mbob","/wizards/punishment/workroom.c");

  /* Boredescit, sattupa tyhjä päivä pään sisällä */
  short_desc = "Punis' most excellent duudsonroom";
  long_desc = "You can see all kind of marks of Punishments\n"+
		"Excellent duudson moves, even photos of it hanging\n"+
		"on the wall making you wonder if theres any 'järki'\n"+
		"involved";

  /* itemeitä kaksin käsin */
  items = allocate(2);
  items[0] = "photo";
  items[1] = "This is a Excellent photo of Punishment performing most excellent\n"+
  	     "Duudsonish' deathtricks";

  /* mun mestassa ei tapella ja muutenkin pitää olla rauhallista */
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";

/*  /* mosat jne npc, myöhemmin */
  if (!present("pikkupiru") {
     move_object(clone_object("/wizards/punishment/hauskat/pikkupiru.c"), this_object());
  }*/
}

init() {
  ::init(); /*hauska patka milla paasee toisten workroomeihin*/
  add_action("kopteri", "lenna");
}

lenna(str) {
  if(!str) {
    write("To where you wanted to kopterize\n"); 
    return 1;
  }
  write("YOU HAVE BEEN KOPTERIZED! Beware the angry dog.\n");
  move_object(this_player(),"/wizards/"+str+"/workroom.c");
  return 1;
}

