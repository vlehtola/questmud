/* dunkkua otsaluuhun-daemon // Celtron */
#define DAMAGE 10
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
  rooms = ({    "/wizards/irmeli/castle/yard2",
                "/wizards/irmeli/castle/yard3",
                "/wizards/irmeli/castle/yard11",
                "/wizards/irmeli/castle/yard17",
                "/wizards/irmeli/castle/yard15",
                "/wizards/irmeli/castle/yard16",
                "/wizards/irmeli/castle/yard10",
                "/wizards/irmeli/castle/yard9",
                "/wizards/irmeli/castle/yard8", 
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
    if(living(ob[i])) {
      tell_object(ob[i], "OUCH, a medium-sized rock drops down from the wall and hits your head making you wriggle with pain.\n");
      ob[i]->hit_with_spell(DAMAGE, "physical");
    }
    i += 1;
  }
}

