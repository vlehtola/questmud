inherit "obj/monster";
object weapon;
object armour;
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("girl");
set_level(10);
set_gender(2);
set_alias("girl");
set_race("human");
set_short("A young girl is here playing");
set_long("You look at the small girl and try to figure out what she \n"+
"is doing. You think she's drawing something in the snow. \n"+
"as you look closer you notice it to resemble a wolf.\n"+
"She looks at her picture nods and starts a new one.\n");
}
