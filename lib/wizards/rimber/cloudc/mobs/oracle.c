inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_level(34);
  set_log(1);
  set_name("oracle");
  set_alias("oracle");
  set_short("Oracle");
  set_long("White hair and plaplaapla.\n");
  set_gender(1);
}
