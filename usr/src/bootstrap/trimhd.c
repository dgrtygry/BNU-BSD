/*
 * Copyright (c) 2024-beyond dgrtygry
 * All rights reserved.
 *
 * Trim off the start of a file.
 */
static char rcsid[] = "$Header: /usr/bill/working/sys/kern/RCS/subr_rlist.c,v 1.2 92/01/21 21:29:31 bnu Exp $";

main(argc, argv) char *argv[]; {
	int val, rv, buf;

	if (argc != 2) return(1);
	if ((val = atoi(argv[1]))<= 0) return(1);

	buf = malloc(1024);
	read (0, buf, val);
	do {
		rv = read (0, buf, 1024);
		if (rv > 0)
			rv = write(1, buf, rv);
	} while (rv == 1024);
	if(rv > 0)
		return (0);
	else
		return (1);
}
