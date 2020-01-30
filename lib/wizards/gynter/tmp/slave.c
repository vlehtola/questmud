// Following slave version 0.1 AlphaBetaDeltaGamma by: Gheldor
// Added example emotes for Torspo to create more. ++Gheldor

// License: Use, modify, but keep the creators on the top of
//          this file _ALWAYS_ or you are using this ILLEGALY!
// ++Gheldor the funny one =)

inherit "obj/monster";
#define OWNER "Gynter"

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("slave");
    set_alias("gynter");
    set_short("A slave is here to follow "+OWNER);
    set_long("A slave, you don't need to know more than that.\n");
    set_al(0);
    set_exp(0);
    set_aggressive(0);
}

heart_beat() {
object ob; 
ob = find_player(lower_case(OWNER));

if(ob) {
  if(environment(ob) != environment(this_object())) {
    tell_room(environment(this_object()), "Slave follows "+OWNER+".\n");
    move_object(this_object(), environment(ob));
    tell_room(environment(this_object()),"Slave walks in after "+OWNER+".\n");
  }
}
}

hit_player(int i) {
i = 0;
return ::hit_player(i);
}

void catch_tell(string str) {
  int i;
  int x;
  string tmp, command, omistaja;
mixed fjant;
fjant = ({"hej",43, "jojo"});
x = 3;

if(sscanf(str,"%s says 'Slave, list file'", omistaja) != 1) return;
if(omistaja != OWNER) return;

  for(i = 0; i < x;i++) {
    fjant[i] = read_file("tempfile", i, i);
  }

  for(i = 0; i < x;i++) {
    write(fjant[i]);
  /*
    write_file("testfile", (string) fjant[i]);
  */
  }
}
