inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) { return; }
set_level(18);
set_name("fox");
set_alias("fox");
set_short("A grey fox sniffing the air");
set_long("A grey fox is sniffing the air and the ground. The fox looks like\n"+
         "it scents something, food or danger. It has upright ears, sharp,\n"+
         "white teeth and long, thick brush. Its thick and soft fur coat\n"+
         "is desired and valuable.\n");
set_al(10);
set_aggressive(0);
set_gender(0);
set_animal(1);
}


