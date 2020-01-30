inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("Rölli");
    set_alias("rölli");
    set_alt_name("rolli");
    set_short("Hirmuinen Rölli");
    set_long("Tulee joskus\n");
    set_level(15);
        
    set_race("human");
       
   
}