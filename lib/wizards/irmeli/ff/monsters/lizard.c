inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) { return; }
set_level(12);
set_name("lizard");
set_short("A nimble lizard (camourflaging)");
set_long("The lizard looks like a snake, except it has four, long and nimble\n"+
         "limbs. It has a long tail, sharp, deadly nails and small, green\n"+
         "eyes. The skin of the lizard is covered with scales, with\n"+
         "different shaped scales.\n");
set_al(0);
set_aggressive(0);
set_gender(0);
set_animal(1);
set_skill("dodge", 60);
set_skill("parry", 60);
set_skill("foresee attack", 60);
set_skill("counter spell", 30);
}
