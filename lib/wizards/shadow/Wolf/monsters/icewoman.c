inherit "obj/monster";
object weapon;
object armour;
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("Woman");
set_level(8);
set_race("human");
set_gender(2);
set_alias("woman");
set_short("An ice-woman is here trying to cook food");
set_long("You look at the woman who is preparing something to eat.\n"+
"She seems to be trying to cook meat over the fireplace.\n"+
"She seems to know what she is doing very well, as the \n"+
"delicious sent to the meat floats around.\n");
}

