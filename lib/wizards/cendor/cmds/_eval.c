// Author : ???
// Headered, rewrote and made to run properly by Cire.
// Cendor added level limit 150 because of security probs.

status cmd_eval( string arg ) {
    string str, filename;
    mixed res, err;
    if( !arg ) {
        notify_fail( "Usage : eval <LPC-commands>\n" );
        return 0;
    }

    str = "mixed eval() {\n" + arg + ";\n}\n";
    filename = "/players/" + this_player() -> query_real_name() +
    "/eval_file.c";

    if( res = find_object( filename ) )
        destruct( res );

    rm( filename );
    write_file( filename, str );

    if( err = catch( res = (mixed)call_other( filename, "eval" ) ) )
        write( "Error = " + err );
    else {
        printf( "Result = %O\n", res );
        if( res = find_object( filename ) ) destruct(res);
    }
    return 1;
}

