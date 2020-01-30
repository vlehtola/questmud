/* dunkkua otsaluuhun-daemon // Celtron */
#define DAMAGE 50
#define INTERVAL 120

reset(arg) {
  if(arg) return;
  call_out("slipping", INTERVAL);
}

slipping() {
  string rooms;
  int i;
  object ob;
  /* huoneet taha */
  rooms = ({    "/wizards/duncan/icecaves/tunnel2",
               
          });
  while(i<sizeof(rooms)) {
    ob = find_object(rooms[i]);
    if(ob) damaa_paahan(ob);
    i += 1;
  }

  call_out("slipping", INTERVAL);
}

damaa_paahan(object room) {
  object ob;
  int i;
  ob = all_inventory(room);
  while(i<sizeof(ob)) {
    if(living(ob[i]) && !ob[i]->query_npc()) {
      tell_object(ob[i], "You slip and fall flat on your face to the ground!\n"+
                         "Your head hits to a nearby pillar, OUCH!\n");
      ob[i]->hit_with_spell(DAMAGE);
    }
    i += 1;
  }
}

