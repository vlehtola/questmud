inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(20);
    set_name("bat");
    set_short("A black bloodsucker bat");
    set_long("A dangerous, black bloodsucker bat. It has small, red eyes, big, bony\n"+
             "wings, razor-sharp teeth, long, black tail, sharp nails and big ears.\n"+
             "Thin, black fur is covering the bat from cold.\n");

    set_animal(1);
    set_gender(0);
    set_al(-50);
    set_aggressive(1);
    set_special(25);
 }

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Bat bites you in neck and sucks some blood!\n");
  say("Bat bites "+ob->query_name()+" in neck and sucks some blood!\n", ob);
  ob->hit_with_spell(50, "physical");
}









