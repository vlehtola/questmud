inherit "obj/weapon";
 
reset(arg) {
        ::reset(arg);
        set_name("demon's fork");
        set_short("A demon's fork");
        set_long("This is mighty tool of battle made of fine mithril.\n" +
                   "You notice some writing in tip of weapon: Fire walk with me!\n");
        set_alias("fork");
        set_wc(80);
         set_weapon_type("axe");
        set_value(16000);
        set_weight(8);
}
hit() {
        if(!wielded_by || !wielded_by->query_attack()) return;
        if(random(10) != 0) return;
tell_room(environment(wielded_by), "Demon's fork glows with bright red light and " +
                "flames erupt from it towards " +wielded_by->query_attack()->query_name()+"!\n");
        wielded_by->query_attack()->hit_with_spell(random(500)+150,1);
        return 1;
}
