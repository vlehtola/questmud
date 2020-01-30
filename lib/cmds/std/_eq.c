cmd_eq(arg) {
    mapping eq;
    object ob,pl;
    int tmp, i;
    string s, slots, tmp_slot;
    string str;
    eq = ([ ]);
    if (!this_player()->test_dark()) { return 1; }
    if (!this_player()->check_condis()) { return 1; }
    ob = this_player();
    if (arg && find_player(arg) && this_player()->query_wiz()) {
        ob = find_player(arg);
    }
    pl = ob;
    ob = first_inventory(ob);
    slots = ({ "forehead", "head", "neck", "amulet", "cloak", "arms", "hands", "right hand",
		"left hand", "both hands", "torso", "belt", "legs", "feet", "tattoo", "gaze"});
    while(ob) {
        if (ob->query_worn() || ob->query_wielded()) {
            str = call_other(ob, "short", 0);
            if (str) {
                if (ob && ob->query_slot()) {
		   tmp_slot = lower_case(ob->query_slot());
                   if(!valid_slot(slots, tmp_slot, ob)) write_log(ob);
		   if(tmp_slot == "finger") {
			write("Finger: " + capitalize(str) + ".\n");
		   } else {
			eq += ([ lower_case(ob->query_slot()) : capitalize(str) ]);
		   }
                 /*  write(capitalize(ob->query_slot()) + ": " + capitalize(str) + ".\n"); */
                }
                else {
		   eq += ([ "right hand" : capitalize(str) ]);
                }
            }
        }
        ob = next_inventory(ob);
    }
  while(i< sizeof(slots)) {
    if(eq[slots[i]]) {
      write( capitalize(slots[i]) +": "+ capitalize(eq[slots[i]]) +"\n");
      eq -= ([ slots[i] ]);
    }
    i += 1;
  }
  str = m_indices(eq);
  tmp = m_values(eq);
  for(i=0;i < sizeof(str); i++) {
    write(capitalize(str[i])+": "+tmp[i]+"\n");
  }

  i = 0;
  ob = pl;
  while(get_bodypart(i)) {
    tmp = ob->query_slot_ac(get_bodypart(i));
    str = get_str(tmp);
    write("Your equipment offers "+str+" protection to your "+get_bodypart(i,1)+".\n");
    i += 1;
  }
  return 1;
}

static valid_slot(string slots, string slot, object ob) {
  int i;
  if(ob && file_name(ob)[0..26] == "/guilds/obj/guild_leader_eq") return 1;
  if(ob && file_name(ob)[0..26] == "/wizards/garath/dragonists/") return 1;

  if(slot == "finger") return 1;
  while(i<sizeof(slots)) {
    if(slot == slots[i]) return 1;
    i += 1;
  }
  return 0;
}

get_bodypart(int i, int text) {
  if(i == 0) return "head";
  if(i == 1 && text) return "torso and arms";
  if(i == 1) return "torso";
  if(i == 2) return "legs";
  return 0;
}

get_str(int tmp) {
  string str;
  str = "no";
  if(tmp > 0) str = "nonexistant";
  if(tmp > 5) str = "very little";
  if(tmp > 10) str = "little";
  if(tmp > 15) str = "poor";
  if(tmp > 25) str = "some";
  if(tmp > 35) str = "low";
  if(tmp > 50) str = "below average";
  if(tmp > 60) str = "average";
  if(tmp > 70) str = "good";
  if(tmp > 80) str = "very good";
  if(tmp > 90) str = "excellent";
  if(tmp >= 100) str = "unearthly";
/*  if(tmp > 120) str = "ILLEGAL"; */
  return str;
}

write_log(ob) {
  if(!this_player()->query_wiz())
    log_file("EQ_ERROR", "Item: "+file_name(ob)+" Slot: "+ob->query_slot()+"\n");
}
