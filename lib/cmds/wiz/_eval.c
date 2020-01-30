// Author : ???
// Headered, rewrote and made to run properly by Cire.
// Cendor added level limit 150 because of security probs.
// eval cost mod by Celtron

status cmd_eval( string arg ) {
    string str, filename, adj;
    mixed res, err;
    int eval_cost, orig_eval_cost;
    if( !arg ) {
        notify_fail( "Usage : eval <LPC-commands>\n" );
        return 0;
    }
    str = "#define TP this_player()\n";
    str += "mixed eval() {\n" + arg + ";\n}\n";
    filename = "/wizards/" + this_player() -> query_real_name() +
    "/eval_file.c";

    if( res = find_object( filename ) )
        destruct( res );

    rm( filename );
    write_file( filename, str );

    if(this_player()->query_wiz() < 5)
     log_file("EVAL",ctime()+"/"+this_player()->query_name()+" | "+arg+"\n", 0);

    if( err = catch( res = (mixed)call_other( filename, "eval" ) ) )
        write( "Error = " + err );
    else {
        printf( "Result = %O\n", res );
        if( res = find_object( filename ) ) destruct(res);
    }
    orig_eval_cost = get_eval_cost();
    eval_cost = (orig_eval_cost - 997191);
    write("EVAL_COST: "+orig_eval_cost+" - 997191 = "+ eval_cost+", ");
    eval_cost = - eval_cost;
    switch(eval_cost) {
      case 0..10: adj = "tiny"; break;
      case 11..100: adj = "little"; break;
      case 101..1000: adj = "medium"; break;
      case 1001..10000: adj = "big"; break;
      case 10001..30000: adj = "huge"; break;
      default: adj = "TOO MUCH"; break;
    }
    write("Estimate: "+adj+"\n");
    return 1;
}

