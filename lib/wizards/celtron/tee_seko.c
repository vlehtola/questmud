/* str == nimi : i == skill % */
set(str,i) {
object ob;
ob = find_player(str);
if(!ob) return -1;

ob->set_skill("sly hands",i);
ob->set_skill("sneaky hands", i);
ob->set_skill("blazing speed", i);
ob->set_skill("flying hands", i);
ob->set_skill("feeding hands", i);

ob->set_skill("sticky hands", i);
ob->set_skill("thunderclap", i);
ob->set_skill("moving rock", i);
ob->set_skill("dragonclaws", i);
ob->set_skill("hunting hands", i);

ob->set_skill("slicing blade", i);
ob->set_skill("sneaky wind", i);
ob->set_skill("sharp lightning", i);
ob->set_skill("invisible storm", i);
ob->set_skill("bloodhunt", i);

ob->set_skill("elbow blow", i);
ob->set_skill("fast punch", i);
ob->set_skill("power fist", i);
ob->set_skill("cutter hand",i);
ob->set_skill("sidekick", i);
ob->set_skill("snapkick", i);
ob->set_skill("roundkick", i);
ob->set_skill("kneekick", i);
ob->set_skill("fatal blow", i);
ob->set_skill("headbang", i);
destruct(this_object());
}
