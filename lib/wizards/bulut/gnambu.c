int i;

inherit "obj/monster";

reset(arg) {
    object collar;
    ::reset(arg);
    if(arg) { return; }
    set_level(61+random(3));
    set_name("gnambu");
    set_alias("hobbit");
    set_short("A hobbit known as Gnambu");
    set_long("Old, wise and dangerous looking Hobbit.\n");
    set_al(0);
    set_mage(1);
    set_aggressive(0);   
    set_log();
    set_special(45);
    set_whimpy(1);

    set_str(query_str()+100);
    set_int(query_int()+100);

    collar = clone_object("/wizards/bulut/collar.c");
    move_object(collar, this_object());
    init_command("wear collar");

}

special_move() {
        if ( this_object()->query_hp() < this_object()->query_max_hp() /2) {
        i = random(4);
                if (!i) {
                tell_room(environment(this_object()),"Gnambu squeezes his collar. Suddenly " +
 capitalize( this_object()->query_attack()->query_name() ) + " disappears!\n");                                                              
 this_object()->query_attack()->move_player("X#wizards/bulut/forl/road2");             
  return 1; }
tell_room(environment(this_object()),"Gnambu squeezes his collar, but nothing happens.\n");
                
        }
}                                     
