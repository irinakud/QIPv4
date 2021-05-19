# QIPv4
The project demostrates how the reusable custom widget `QIPv4Edit` works:
* The widget only supports IPv4 IP address entry.
*	The IP Address displayed in the widget is formatted "naturally", i.e. 127.0.0.1 not 127.000.000.001. Padding with spaces is allowable, e.g. 127.  0.  0.  1.
*	The widget does not accept invalid user inputs.
*	The widget provides a read/write property of address so the client code can access the IP Address from programming.
