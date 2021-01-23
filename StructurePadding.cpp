#include <iostream>
using namespace std;

// CPU không truy xuất dữ liệu từng byte riêng lẻ mà theo từng khối dữ liệu có dung lượng 2^N bytes như 2, 4, 8, 16, và 32 bytes tùy hệ thống
// Lý do là vì tốc độ truy xuất dữ liệu theo khối nhanh hơn rất nhiều so với bằng từng byte

// Việc truy nhập theo từng khối dẫn đến quá trình thao tác dữ liệu trong bộ nhớ sẽ diễn ra ở các vùng địa chỉ
// có giá trị bằng NGUYÊN lần dung lượng khối dữ liệu truy nhập
// Ví dụ như truy xuất khối dữ liệu có dung lượng 4 bytes, các địa chỉ dữ liệu có thể thao tác là 0x0000, 0x0004, 0x0008, ...

// Đơn vị nhỏ nhất lưu trữ trong bộ nhớ là 1 byte, mỗi byte được đánh địa chỉ và sắp xếp liên tục nhau như số nhà trên 1 con đường
// Một biến int có sizeof int là 4 bytes, vậy để lưu trữ biến này ta cần 4 bytes đánh địa chỉ liên tục nhau
// PC muốn access biến này thì phải cần 4 cycles, mỗi cycle access 1 byte
// Thật tuyệt vời nếu 1 cycle mà access được biến int

// PC sẽ processing the length of word as bus size
// Để làm vậy thì cấu trúc bộ nhớ được sắp xếp thành group 4 banks trên 1 row, mỗi bank là 1 byte thành 4 banks địa chỉ liên tục nhau
// 2 rows liên tục nhau thì địa chỉ khác nhau N bytes

// Mỗi cycle access thì PC access 1 row (gọi là 1 word) thì sẽ fetch được biến int 4 bytes
// 32bits thì 1 word có 4 bytes, 64bits thì 1 word có 8 bytes, 16bits thì 1 word có 2 bytes
// Như vậy, cấu trúc bộ nhớ trở thành các words đánh địa chỉ liên tục nhau 100 -> 104 -> 108...(32bit), 100 -> 108 -> 116...(64 bit)
// Địa chỉ X sẽ là multiple của 1 word (32bit = 4 bytes, 64bit = 8 bytes), 1 cycle PC sẽ fetch được 1 word (32bit = 4 bytes, 64bit = 8 bytes)
// Ví du: 32 bit mà muốn fetch 1 biến double 8 bytes thì cần 2 cycles, trên 64 bit thì chỉ cần 1 cycle
// Đó là DATA ALIGNMENT (A variable’s data alignment deals with the way the data stored in these banks.)
// Data Alignment đơn thuần chỉ là XÁC ĐỊNH ĐỊA CHỈ LƯU DỮ LIỆU

// Thế nào là STRUCTURE PADDING?
// C/C++ có data type là structure, là 1 data package contains nhiều data type nhỏ
// struct ImStruct {char Im; int Struct};
// DATA ALIGNMENT một struct theo cách tự nhiên, tuần tự theo cấu trúc bộ nhớ gọi là STRUCTURE PADDING
// Data padding là để làm được data alignment trên chúng ta cần phải “padding” thêm một số padded bytes
// để địa chỉ các thành phần của struct có thể ở địa chỉ is mutiple of 1 word (Chia hết cho 2^N)

// RULE: Address X(to decimal) is mutiple of 1 word (Chia hết cho 2^N)
// Địa chỉ của dữ liệu là một số ‘chẵn’ – địa chỉ dữ liệu chia hết cho dung lượng khối dữ liệu có thể truy xuất 2^N bytes (2, 4, 8, 16, … 2^N bytes)
// If an integer of 4 bytes is allocated on X address (X is multiple of 4)
// If an double of 8 bytes is allocated on X address (X is multiple of 8)

// It will be of the largest member of the structure (1)
// Ý là data alignment sao cho fetch 1 lần là có được dữ liệu của data type đó rồi, PC chỉ access ĐỊA CHỈ BẮT ĐẦU của khối dữ liệu 2^N bytes (2)
// Thứ tự thành phần struct sẽ thay đổi sizeof struct, datatype có sizeof smaller thứ tự gần nhau sẽ làm giảm sizeof struct (3)

// Alignment Boundary hay N-byte Alignment chỉ số byte cao nhất mà dữ liệu có thể truy nhập theo khối
// tức số N lớn nhất mà địa chỉ dữ liệu chia hết (N là hàm mũ cơ số 2)
// Ví du: 0x12FEEC = 1244908 (Cơ số 10) có N = 4

// What is structure packing?
// Ví dụ khi đọc file ELF, JPEG, BMP header, chúng ta khộng cần STRUCTURE PADDING kiểu DATA ALIGNMENT như trên
// Chúng ta cần chính xác structure như header file layout, tức là sẽ fetch byte by byte (fetch riêng lẻ từng byte)
// Ta dùng #pragma pack (1)

int main ()
{
	// #pragma pack (1)
	// Giả sử based address của struct là 0x0000 0000 (1 word = 32 bits = 4 bytes)
	struct Mot
	{
		char M; // 1 bytes
		short int ot; // 2 bytes
		// struct này có sizeof là 4 bytes, chú ý address của short int là 0x0002
		// Sẽ có 1 empty memory block vào giữa char và short int vì nếu không có thì start address của short int là 0x0001 (không thỏa mãn RULE)
	};
	cout << sizeof(Mot) << endl;

	struct Hai
	{ 
    	short int   s; // 2 bytes, start address 0x0000 -> 0x0001
    	char        c; // 1 bytes, start address 0x0002, 1 byte empty padding ở 0x0003
   		int         i; // 4 bytes, start address 0x0004 -> 0x0008 4 bytes của int sẽ padding sang word mới
   		// sizeof Hai là 8 bytes
	};
	cout << sizeof(Hai) << endl;

	struct Ba 
	{ 
    	char        c; // 1 byte, start address 0x0000 0000 -> 0x0000 0007, 7 bytes tiếp theo là empty bytes 
    	double      d; // 8 bytes, start address 0x0000 0008 -> 0x0000 000F (sang word mới)
   		int         s; // 4 bytes, start address 0x0000 0010 -> 0x0000 0017, 4 bytes empty padding (sang word mới, vì double đã chiếm 2 words trước đó)
   		// sizeof Ba là 24 bytes
   		// Lý do: It will be of the largest member of the structure
	};
	cout << sizeof(Ba) << endl;
  
	struct Bon 
	{ 
    	double      d; // 8 bytes, start address 0x0000 -> 0x0007
    	int         s; // 4 bytes, start address 0x0008 -> 0x000B
    	char        c; // 1 bytes, start address 0x000C, 0x000D -> 0x000F là 3 bytes empty padding
    	// sizeof Bon là 16 bytes
	};
	cout << sizeof(Bon) << endl;

	struct Nam
	{
    	char c; // 1 byte, 0x0000, + 3 padded bytes at 0x0001 -> 0x0003 (4 bytes)
    	int i; // 4 bytes, 0x0004 -> 0x0007 (4 bytes, 2 thằng trên cùng word)/Nếu int ở trên row với char thì phải mất 2 cycles để fetch int 4 bytes
    	short s; // 2 bytes, 0x0008 -> 0x0009, + 6 padded bytes at 0x000A -> 0x000F (8 bytes)
    	double d; // 8 bytes, 0x0010 -> 0x0017 (8 bytes)
    	// sizeof Nam la 24 bytes
	};
	cout << sizeof(Nam) << endl;

	struct Sau
	{
     	char c; // 0x0000, 3 padded bytes 0x0001 -> 0x0003 
     	int i; // 0x0004 -> 0x0007 (8 bytes)
    	double d; // 0x0008 -> 0x000F (8 bytes)
    	// sizeof Sau la 16 bytes
	};
	cout << sizeof(Sau) << endl;

	struct Bay
	{
     	char c; // 0x0000, 1 padded byte 0x0001
     	short s; // 0x0002 -> 0x0003
     	// sizeof Bay la 4 bytes
	};

	cout << sizeof(Bay) << endl;

	return 0;
}