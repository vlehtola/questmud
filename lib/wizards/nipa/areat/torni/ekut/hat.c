inherit "obj/armour";
reset(arg) {
    ::reset(arg);
    set_name("hat");
    set_alias("Hat");
    set_short("A black pointed magehat with golden stars");
    set_long("This pointed magehat is pitch black and it is decorated with\n"
             "golden stars. These pointed black hats were traditionally given\n"+
             "to newly graduated mages but are now days only given to best\n"+ 
             "student of the year. Although these hats are only moderately\n"+
             "enchanted they are used for show off. This particular hat seems\n"+
             "to be somehow corrupted and its stars seem to have lost some of\n"+ 
             "their glow. Also this hat seems to be mistreated and it looks\n"+
             "kindof tattered");
    set_ac(1);
    set_value(500);
     set_weight(100);
    set_stats("int", 2);
    set_stats("wis", 2);
    set_stats("spr", 5);
    set_slot("head");
}
