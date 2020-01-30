/* * * * * * * * * * * * * * * * * * * *
 *                                     *
 *     This trap is to be used         *
 *     in a room with no exits..       *
 *                                     *
 * * * * * * * * * * * * * * * * * * * */

inherit "/wizards/gynter/daemons/trap";

object ob;
start() {
  set_alias("shimmer");
  set_name("shimmer");
  short_desc = "A magical shimmer";
  long_desc = "A faint magical shimmer. It seems soft to the skin as you walks in it.\n"+
              "Maybe if you are fast enough you can capture some in your hand.\n"+
              "But.. it's very hard to move in here... you really have to utilize\n"+
              "all of your powers to move in it.\n";

  damage = 500;
  active = 1;
  execute_mess = "As you try to touch the shimmer you get an electric shock.\n";
}

init() {
  add_action("tc", "touch");
  add_action("eastie", "east");
}

eastie() {
  if(!ob) ob = this_player();
  if(ob->query_npc()) return;
  tell_object(ob,"As you try to move you realise that you are trapped in the shimmer.\n");
  tell_object(ob,"And as you move through the shimmer you feel small electrical shocks.\n");
  ob->hit_with_spell(150);
  return 1;
}

tc(str) {
  if(!ob) ob = this_player();
  if(str != "shimmer") {
    write("The shimmer zaps you as you move thru it...\n");
    ob->hit_with_spell(150);
    return 1;
  }
  tell_object(ob,execute_mess);
  ob->hit_with_spell(damage);
  return 1;
}
