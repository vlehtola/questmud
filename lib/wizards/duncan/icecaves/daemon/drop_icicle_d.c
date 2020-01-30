/* dunkkua otsaluuhun-daemon // Celtron */
#define DAMAGE 20
#define INTERVAL 40

reset(arg) {
  if(arg) return;
  call_out("rocks", INTERVAL);
}

rocks() {
  string rooms;
  int i;
  object ob;
  /* huoneet taha */
  rooms = ({    "/wizards/duncan/icecaves/hall",
                "/wizards/duncan/icecaves/hall1",
          });
  while(i<sizeof(rooms)) {
    ob = find_object(rooms[i]);
    if(ob) damaa_paahan(ob);
    i += 1;
  }

  call_out("rocks", INTERVAL);
}

damaa_paahan(object room) {
  object ob;
  int i;
  ob = all_inventory(room);
  while(i<sizeof(ob)) {
    if(living(ob[i]) && !ob[i]->query_npc()) {
      tell_object(ob[i], "OUCH! A small icicle drops down from the ceiling and hits your head, making you wriggle with pain.\n");
      ob[i]->hit_with_spell(DAMAGE);
    }
    i += 1;
  }
}

