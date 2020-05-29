/**
 * Read a text file by lines accordingly a number of clients
 *
 * Author: CI0117 Programacion paralela y concurrente
 * Date: 2020/May/28
 *
 *
 * The file can be read using four strategies:
 *   a) The file is divided in almost equal parts (number of lines) the first part is assingned to first worker, second part to second worker, and so on
 *   b) The file is assigned one line to each worker, first worker takes all lines which line number modulus number of clients is zero, the second which modulus is one, and so on
 *   c) The file is read by demand, one line for each worker who needs it
 *   d) A personal developed strategy 
 *
 * Project restrictions
 *   - This class will hold in memory only one line for each worker (max. 1024 bytes)
 *   - The file can be opened just one time for each instance of this class
 *
 */

class FileReader {

private:
   // Suggested (example) variables, may be dropped if you dont mind to use them
   int workers;				// Workers that read the file
   int strategy;			// Strategy to read the file, see cases above
   int totalLines;			// Total lines in file
   FILE * fileId;			// Identifier for opened file
   // ...
   // Other variables you may need in your class

public:
   // Example methods, you can delete or rewrite them if necessary
   FileReader( const char * fileName, int workers = 1, int strategy = 1 );
   ~FileReader();
   bool hasNext( int worker = 0 );
   int getNext( char ** line, int worker = 0 );
   // ...
   // Other methods you may need

};

