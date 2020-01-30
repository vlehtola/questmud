inherit "obj/monster";
object weapon;
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(200);
    set_name("Merchant");
    set_alias("merchant");
    set_gender(2);
    set_al_aggr(400);
set_log();
    set_str(query_str()*2);
    set_short("Merchant, the forger of magical items");
    set_long("She's a special merchant that can forge rubys into rings.\n");
    set_al(90);
    set_aggressive(0);
    }
   
    catch_tell(str) {
    string giver,tmp;
    object ob, ruby, award;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives huge ruby to %s", giver, tmp) == 2) {
    ob = present(lower_case(giver),environment(this_object()));
    if (!ob) { return; }
    ruby = present("ruby", this_object());
    if (!ruby) { return; }
    tell_object(ob, "Merchant says: 'Here's the ruby ring of the sands.'\n");
    award = clone_object("/wizards/arylith/area_project/items/ring_caster"); 
    move_object(award, this_player());
}
}
destroy_ruby(object ruby) {
  destruct(ruby);
}
