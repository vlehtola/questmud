inherit "obj/weapon";
int charge, ready, tmp;

start() {
	charge = 5;
        tmp = 0;
	ready = 1;
	set_name("warhammer");
	set_sub_type("warhammer");
        set_class(9);
        set_short("A black warhammer");
 set_long("This warhammer seems to suck all the light. It's surface is\n"+
  "black and cold. It is well balanced and easy to use\n"+
  "despite it is heavy. The fine leather strap wrapped around\n"+
  "warhammer's iron shaft makes it possible to get a superior grip\n"+
  "of the weapon. The symbol of overlapping moon and the sun can\n"+
  "be seen carved on the warhammer's head.\n");
}

hit() {
 wielded_by = this_player();
      if(!wielded_by || !wielded_by->query_attack()) return;
      if(random(101) < 91) return;
       if(charge > 0) {
	charge -= 1;
	write("Warhammer starts to glow brightly and for a while you don't see anything.\n"+
	      "Suddenly darkness surrounds you and bright blue lightning strikes out\n"+
 "of nowhere and hits before "+wielded_by->query_attack()->query_name()+".\n");
 say("Darkness gathers around "+this_player()->query_name()+" and suddenly bright blue lightning strikes before "+wielded_by->query_attack()->query_name()+".\n");
       wielded_by->query_attack()->hit_with_spell(random(101)+200,"electric");
       }
        if(charge == 0 && tmp == 0) {
	write("Warhammer turns to black like sucking all the light around it.\n");
       say(this_player()->query_name()+"'s warhammer turns to black.\n");
	ready = 0;
        tmp = 1;
        call_out("lataus", 50);
	}
}

int lataus() {
	charge = 5;
       tmp = 0;
	write("The warhammer starts to radiate deep blue light.\n");
        say(this_player()->query_name()+"'s warhammer starts to radiate deep blue light.\n");
	ready = 1;
}
