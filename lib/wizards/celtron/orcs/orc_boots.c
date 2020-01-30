inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("boots");
    set_short("Spiked black iron boots");
    set_long("These boots have several nasty looking spikes, but yet they feel surprisingly good on your feet.\n");
    set_ac(80);
    set_value(10000);
    set_weight(5);
    set_slot("feet");
    set_stats(1,5);
    set_stats(2,8);
    set_stats(3,10);
    set_stats(4,-7);
    set_stats(5,-7);
    set_stats(6,5);
    set_stats(7,-10);
}
