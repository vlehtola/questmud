inherit "obj/armour";
  start() {

   set_class(1);
   set_name("head");
   set_short("Head of an Angel (frozen)");
   set_long("The head has been cutted off from an angel's body. The head is old and\n"+
            "uncomposable, because it's frozen.\n");
 
 }


drop(arg) {

  object ob;
  ob = environment(environment(this_object()));
  if(!ob->head_location()) {
    return 0;
  }

  tell_room(ob, "An angel appears among the clouds, lands onto the ground\n"+
                "and takes the head.\n");
  tell_room(ob, "Enchantress says: 'This is the head of my husband, I'll\n"+
                "revenge this!'\n");
  move_object(clone_object("/wizards/irmeli/valley/monsters/fallen.c"), ob);
  this_player()->set_quest("Lure the Enchantress");
  destruct(this_object());

  return 1;
}
