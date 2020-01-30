init() {
    
    add_action("mcheck", "mcheck");
    add_action("mdie", "mdie");
    add_action("mdrink", "mdrink");
    add_action("msommersault", "mjump");

}

id() {
    return "watch";
}
alias() {
    return "watch";
}
        
name() {
    return "watch";
}

short() {
    return "A little wrist watch";
}

long() {
    return "You are looking at a little wrist watch.";
 
}

mcheck() {
        write("Damn, your looking good!\n");
        say(call_other(this_player(), "query_name", 0) +
            " looks at his mirror and says: Damn, I'm looking good!\n");
        return 1;
    }

mdie() {
        write("Damn, That bastard's gonna pay for messing up my day!\n");
        say(call_other(this_player(), "query_name", 0) +
            " says: Damn, That bastard's gonna pay for messing up my day!\n");
        return 1;
    }

mdrink() {
        write("computer, earl grey tea, hot!\n");
        say(call_other(this_player(), "query_name", 0) +
            " says: computer, Earl grey tea, hot!\n");
        return 1;
    }

msommersault() {
        write("You jump up and do a perfect sommersault with a 360 degree spin!\n");
        say(call_other(this_player(), "query_name", 0) +
            " jumps up and does a sommersaults with a 360 degree spin.\n");
        return 1;
    }
