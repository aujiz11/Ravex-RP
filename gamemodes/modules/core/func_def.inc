#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
    
#define Function:%0(%1) \
    forward %0(%1); public %0(%1)

#define SendSyntaxMessage(%0,%1) \
    SendClientMessage(%0, 0x61B15DFF, "SYNTAX: {BDBDBD}"%1)