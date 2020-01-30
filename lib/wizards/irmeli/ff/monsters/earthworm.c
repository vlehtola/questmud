inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) { return; }
set_level(8);
set_name("earthworm");
set_alias("worm");
set_short("A lifeless earthworm (frozen)");
set_long("A snake-like, lifeless looking, frozen earthworm. The earthworm\n"+
         "has no limbs, backbone or eyes. It's medium-sized, or atleast\n"+
         "it was, before it become frozen.\n");
set_al(40);
set_aggressive(0);
set_gender(0);
set_animal(1);
}


