inherit "obj/monster";

reset(arg) {
::reset(arg);
if (arg) { return; }
    set_level(42);
    set_name("banshee");
    set_alias("knight");
    set_short("A banshee from the netherworld ");
    set_long("Before you is an apparition of incomprehensible horror. The \n"+
             "purpose to prevent him to fly. The regular celestial angel-look is far away\n"+
             "from him. First of all, his eyes are full of rage, secondly his body is full\n"+
             "of scalds and wounds from whiplashes and finally he is bold. He has broked up\n"+
             "from chains, chains which are in his legs and hands.\n");

    set_al(-90);
    set_gender(2);
    set_race("angel");
    set_aggressive(1);
    set_mage(1);
    set_undead();
    set_special(100);


}


special_move() {

     object players, target, room;
     int i;
     
     room = environment(this_object());

     players = all_inventory(room);
     players = filter_array(players, "filtteri");


     i = sizeof(players);
    
     target = players[random(i)];

     tell_object(target,"Banshee lets out a shriek that chills your soul to the bone!\n");
     tell_room(room,"Banshee screams chilling the soul of "+target->query_name()+" to the bone!\n");
     target->hit_with_spell(5000, "cold");

}


    
 
status filtteri(object ob) {
        if(living(ob) && !ob->query_npc()) return 1;
        return 0;
}


