inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(32);
    set_name("angel");
    set_alias("slave");
    set_short("A skeletal angel slave");
    set_long("An knobbly, skeleton-like, lashed, skinny angel is walking around\n"+
             "in chains. His bones are shining through his thin skin, especially\n"+
             "in his stomach, face and legs. The small, bony wings, growing from\n"+
             "his backbone are rudimented.\n");

    set_al(50);
    set_gender(1);
    set_race("human");
    set_aggressive(0);
    set_special(25);
  }


special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Angel strangles you with his chains!\n");
  say("Angel strangles "+ob->query_name()+" with his chains!\n", ob);
  ob->hit_with_spell(100, "physical");
}





