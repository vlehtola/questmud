inherit "room/room";

reset(arg) {
  short_desc = "Falling down in the mid-air";
  long_desc =  "You are falling down towards melting mass with accelerating speed.\n";

  set_not_out(1);
  property = ({"no_kill", "no_skill", "no_spell", "no_summon"});
}
