object player;

start(object ob) {
  player = ob;
  shadow(player, 1);

}
short() {
  return player->short()+"(shadowed)";
}
