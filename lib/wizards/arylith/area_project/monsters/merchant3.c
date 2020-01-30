inherit "obj/monster";
object weapon;
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(200);
    set_name("Merchant");
    set_alias("merchant");
    set_gender(1);
    set_al_aggr(400);
set_log();
    set_str(query_str()*2);
    set_short("Desert merchant");
    set_long("He gives money to those who returns worm scales to him.\n");
    set_al(90);
    set_aggressive(0);
    }
    catch_tell(str) {
    string giver,tmp;
    object ob, scale, award;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives huge worm scale to %s", giver, tmp) == 2) {
    ob = present(lower_case(giver),environment(this_object()));
    if (!ob) { return; }
    scale = present("scale", this_object());
    if (!scale) { return; }
tell_object(ob, "Merchant says: 'Good job! Here's the reward, 1 mithril coin.'\n");
    award = clone_object("/obj/new_money");
    award->set_type(6);
award->add_value(1);
    move_object(award, this_player());
    return 0;
}
}
destroy_scale(object scale) {
destruct(scale);
}
