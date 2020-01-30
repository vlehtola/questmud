inherit "obj/monster";

id(str) { return str == "spec"; }

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_block_dir("south");
  set_block_message("The passageway has collapsed and you cannot continue that way.");
}