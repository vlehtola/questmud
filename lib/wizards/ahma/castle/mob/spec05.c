inherit "obj/monster";

id(str) { return str == "spec"; }

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_block_dir("west");
  set_block_message("You cannot continue further due to the collapsed ceiling.");
}
