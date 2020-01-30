inherit "obj/weapon";

start() {
set_class(6);
set_sub_type("claymore");
set_alias("renisa");
set_slayer("ogre");
set_short("A white claymore named 'Renisa'");
set_long("The blade of claymore is made from mithril and on the surface of blade\n"+
         "is no marks of battle. The hilt is strong looking and quite sturdy. The\n"+
         "blade is some how changing the colour every time of something different race\n"+
         "is coming the room. This must be one of the legendary slayer weapons, but you\n"+
         "can't guess which kind of slayer.\n");
}

hit() {
	if(!wielded_by || !wielded_by->query_attack()) return;
	if(wielded_by->query_race() == "ogre") {
		write("The claymore burns your hands and forces you to drop the weapon.\n");
		wielded_by->hit_with_spell(500+random(600), "fire");
		this_object()->unwield(this_object());
		return 1;
	}
}
