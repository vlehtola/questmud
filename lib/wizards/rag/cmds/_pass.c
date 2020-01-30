
cmd_pass(str) {
        if ( !str ) {
                write("No no no!\n");
                return 1;
        }

        write( crypt(str,str) + "\n" );
        return 1;
}
