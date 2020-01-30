inherit "obj/monster";

reset(arg) {
  string str;
  ::reset(arg);
  if(arg) return;
  set_level(70);
  set_name("suin");
  set_alias("master");
  set_short("Suin, the master of the martial arts");
  set_long("Suin is a short and nimble man. He starts to be middle aged.\n"+
           "He has bright eyes and a strong chin. Dressed in a simple\n"+
           "robe, he watches after his young students.\n"+
           "He might be able to give you new robes if you have lost your previous ones.\n");
  set_al_aggr(300);
  str = allocate(4);
  str[0] = "Suin examines your body.\n";
  str[1] = "Suin says: 'Say if you seek a way I can lead you to.'\n";
  str[2] = "Suin makes some strange maneuvers.\n";
  str[3] = "Suin says: 'Say if you seek a way I can lead you to.'\n";
  load_chat(15,str);
  set_gender(1);
/*
  move_object(clone_object("/obj/robe"),this_object());
  init_command("wear robes");
*/
}
catch_tell(arg) {
  string str,tmp,tmp2;
  if(sscanf(arg, "%s says 'robes'",str) == 1) {
    if(!present("robes",this_player())) {
        write("Suin gives you new robes and smiles warmly.\n");
        move_object(clone_object("/obj/robe"), this_player());
        return 1;
    }
    write("Suin says 'But you already have ones.'\n");
    return 1;
  }
  if(sscanf(arg, "%s says 'I seek the %s'",str,tmp) == 2) {
    while(sscanf(tmp, "%s %s",tmp,tmp2) == 2) {
      tmp = tmp + "_" + tmp2;
    }
    if(file_size("/guilds/artist/guilds/"+tmp+".c") == -1) {
      tell_room(environment(this_object()), "Suin says: 'You seek a wrong path, shame on you!'\n");
      return 1;
    }
    if(!call_other("/guilds/artist/guilds/"+tmp, "check_joining_rec")) {
      tell_room(environment(this_object()), "Suin says: 'You are not yet worthy for such a knowledge.'\n");
      return 1;
    }
    tell_room(environment(this_object()), "Suin says: 'Very well.. be diligent and train hard.'\n");
    this_player()->move_player("", "/guilds/artist/guilds/"+tmp);
    return 1;
  }
  return 0;
}





