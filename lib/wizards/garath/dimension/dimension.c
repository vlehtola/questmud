inherit "room/room";

reset(arg) {


  add_exit("cs","/world/city/cs");

  short_desc = "A mysterious dimension";
  long_desc = "You have been transferred to a mysterious dimension. Everything is white\n"+
              "and misty, it feels like you were inside clouds. The visibility is poor,\n"+
              "and the thick air is cold and heavy. You are in the air, weightless,\n"+
              "floating around without any destination. It's almost impossible to\n"+
              "breathe in here, because the air is freezing cold.\n";

  property = allocate(2);

  property[0] = "no_summon";
  property[1] = "no_tele";
  set_heart_beat(1);
}

void heart_beat() {
  int i;
  object *obs,*players;
  if(random(15)) return;
  obs = all_inventory(this_object());
  players = ({ });
  for(i=0;i<sizeof(obs);i++) {
     if(!obs[i]->query_armour() && !obs[i]->query_weapon() && !obs[i]->query_monster())
       players += ({ obs[i], });
  }
  for(i=0;i<sizeof(players);i++) {
     tell_object(players[i],"Your lungs freezes as you breath the cold air, making you cough up blood.\n");
     tell_object(players[i],"Breathing really hurts!\n");
     players[i]->hit_with_spell(25+random(100));
  }
}
