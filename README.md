BÁO CÁO CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT
Môn học: Cấu trúc dữ liệu và giải thuật
Sinh viên: 	Nguyễn Đoàn Như Ý – 25120475
		Nguyễn Minh Quyến – 25120427
		Phan Tuấn Vinh – 25120472
Thời gian học: Học kỳ II năm học 2025 -2026

I.	Integer Sort
1	THUẬT TOÁN TỐT NHẤT Ở LẦN CHẠY THỨ NHẤT
1.1	Thuật toán được lựa chọn
Trong lần chạy đầu tiên, thuật toán được lựa chọn để giải quyết bài toán Integer Sort là
LSD Radix Sort 16-bit với cơ số:

216 = 65536

Mục tiêu chính của phương pháp này là giảm số lượt xử lý dữ liệu đối với số nguyên 32-bit. Thay vì phải thực hiện nhiều lần phân phối như Radix Sort cơ số nhỏ, việc sử dụng cơ số 216 cho phép hoàn thành quá trình sắp xếp chỉ sau 2 lượt quét dữ liệu (Pass).
So với các thuật toán sắp xếp dựa trên phép so sánh như Quicksort hoặc Mergesort, Radix Sort phù hợp hơn với bài toán sắp xếp số nguyên quy mô lớn nhờ đặc tính xử lý tuyến

1.2	Ý tưởng cài đặt
Thuật toán được xây dựng dựa trên nguyên lý Least Significant Digit (LSD), nghĩa là xử lý dữ liệu từ nhóm bit thấp đến nhóm bit cao. Với kiểu dữ liệu số nguyên 32-bit, mỗi giá trị được chia thành hai nhóm 16-bit, tương ứng với hai lượt xử lý.


Bước 1: Đồng bộ miền giá trị
Do dữ liệu đầu vào bao gồm cả số âm và số dương, việc sắp xếp trực tiếp theo bit có thể gây sai lệch thứ tự. Để khắc phục, chương trình sử dụng phép biến đổi:
x ⊕ 0x80000000
Phép toán này giúp chuyển miền giá trị:[−231, 231 − 1] thành: [0, 232 − 1]
nhằm đưa toàn bộ dữ liệu về dạng không dấu, từ đó đảm bảo thứ tự sắp xếp được bảo toàn.
Bước 2: Xử lý 16 bit thấp
Ở Pass đầu tiên, thuật toán trích xuất 16 bit thấp của từng phần tử bằng biểu thức: (arr[i] >> 0) & 0xFFFF
Sau đó thực hiện: Đếm số lần xuất hiện của từng giá trị, tính tổng tích lũy (prefix sum), và phân phối phần tử sang mảng trung gian temp.
Bước 3: Xử lý 16 bit cao
Ở Pass thứ hai, thuật toán tiếp tục xử lý nhóm bit cao bằng: (arr[i] >> 16) & 0xFFFF

Quy trình đếm và phân phối được thực hiện tương tự trên dữ liệu đã qua lượt xử lý đầu tiên. Để hạn chế chi phí sao chép mảng sau mỗi Pass, chương trình sử dụng: arr.swap(temp);
Phép toán này chỉ thực hiện hoán đổi vùng quản lý bộ nhớ của vector, giúp giảm chi phí xử lý trên tập dữ liệu lớn

1.3	Các kỹ thuật tối ưu hóa đã sử dụng
a)	Tối ưu thuật toán
Biến đổi bit dấu (XOR Transformation): Thay vì xử lý riêng số âm và số dương bằng các nhánh điều kiện (if-else), chương trình sử dụng phép XOR với 0x80000000 để chuẩn hóa toàn bộ miền dữ liệu sang dạng không dấu. Điều này giúp đơn giản hóa luồng xử lý và duy trì hiệu năng ổn định.
b)	Tối ưu bộ nhớ
Tái sử dụng mảng phụ: Mảng trung gian temp được cấp phát một lần với kích thước N trước khi thuật toán bắt đầu và được tái sử dụng trong toàn bộ quá trình xử lý. Việc này giúp giảm chi phí cấp phát bộ nhớ lặp lại.

c)	Tối ưu CPU
Sử dụng phép toán bitwise: Các toán tử dịch bit (») và toán tử AND (&) được sử dụng để trích xuất giá trị thay cho phép chia (/) hoặc chia dư (%), giúp giảm chi phí tính toán.
d)	Tối ưu nhập/xuất
Để tăng tốc độ xử lý dữ liệu đầu vào và đầu ra, chương trình áp dụng cấu hình vô hiệu hóa đồng bộ luồng và giải phóng liên kết đệm. Ngoài ra, ký tự xuống dòng ’\n’ được ưu tiên thay cho endl nhằm tránh thao tác flush buffer không cần thiết.
1.4	Phân tích độ phức tạp
Do số lượt xử lý được cố định ở mức 2, độ phức tạp của thuật toán gần như không phụ thuộc vào phân bố dữ liệu đầu vào.
•	Best Case: O(2 · (N + 65536)) ⇒ O(N )
•	Average Case: O(2 · (N + 65536)) ⇒ O(N )
•	Worst Case: O(2 · (N + 65536)) ⇒ O(N )
•	Bộ nhớ sử dụng: O(N + 65536) bao gồm mảng phụ temp kích thước N và mảng đếm count gồm 65536 phần tử.

1.5	Lý do thuật toán này hiệu quả nhất ở lần chạy thứ nhất

•	Số lượt xử lý thấp: Với cơ số 216, thuật toán chỉ cần đúng 2 Pass để xử lý số nguyên 32-bit, giúp giảm số lần quét mảng.
•	Hiệu năng tuyến tính: Radix Sort có độ phức tạp tuyến tính O(N ), hoàn toàn phù hợp với tập dữ liệu lớn như N = 105.
•	Ổn định với nhiều kiểu dữ liệu: Thời gian thực thi gần như không thay đổi đáng kể dù dữ liệu đầu vào ngẫu nhiên, đã sắp xếp hay đảo ngược.

2	THUẬT TOÁN TỐT NHẤT Ở LẦN CHẠY THỨ NHẤT KHÔNG ĐỔI (CẢI TIẾN LẦN HAI)
2.1	Ý tưởng cải tiến
Mặc dù phiên bản Radix Sort 16-bit có ưu điểm là số lượt xử lý ít, kích thước lớn của mảng count vẫn ảnh hưởng đến khả năng truy cập bộ nhớ cache. Cụ thể:
65536 × 4 bytes ≈ 256 KB
Kích thước này vượt quá dung lượng L1 Data Cache của phần lớn CPU hiện đại.
Để cải thiện vấn đề trên, thuật toán được điều chỉnh sang LSD Radix Sort 8-bit với cơ số:
28 = 256
Khi đó không gian chiếm dụng giảm mạnh:
256 × 4 bytes = 1 KB
Mặc dù số Pass tăng từ 2 lên 4, mảng đếm nhỏ hơn giúp dữ liệu được lưu giữ hiệu quả hơn trong cache tốc độ cao, tối ưu hóa băng thông luồng dữ liệu.
2.2	Các tối ưu mới 
Tối ưu bộ nhớ: Mảng đếm được chuyển từ cấu trúc cấp phát động sang mảng tĩnh thô int count[256] để loại bỏ hoàn toàn chi phí quản lý bộ nhớ trên vùng Heap.
Tối ưu cache: Kích thước nhỏ gọn 1 KB của mảng count giúp tăng cường tính cục bộ dữ liệu (Cache Locality) và hạn chế tối đa các lỗi Cache Miss.
Tái sử dụng bộ nhớ: Mảng tạm temp tiếp tục được cấp phát duy nhất một lần và duy trì tái sử dụng xuyên suốt toàn bộ tiến trình.




2.3	So sánh với lần chạy thứ nhất


Thành phần	
Lần 1	
Lần 2

Thuật toán	Radix Sort 16-bit	Radix Sort 8-bit
2	4
Số Pass

≈ 256 KB	≈ 1 KB
Bộ nhớ count

O(N )	O(N )
Độ phức tạp

2.4	Kết quả đạt được
Sau khi tối ưu, phiên bản Radix Sort 8-bit cho kết quả ổn định hơn trên các bộ test dữ liệu lớn. Mặc dù số lượt xử lý tăng lên, việc giảm kích thước mảng đếm giúp cải thiện khả năng tận dụng CPU Cache, từ đó giảm đáng kể chi phí truy cập bộ nhớ RAM vật lý. Tuy nhiên, thuật toán vẫn cần sử dụng mảng phụ temp kích thước O(N ), khiến mức sử dụng bộ nhớ cao hơn các thuật toán sắp xếp tại chỗ (In-place sort).






3	KẾT LUẬN
Qua quá trình benchmark và tối ưu, LSD Radix Sort 8-bit kết hợp biến đổi bit dấu bằng XOR được đánh giá là giải pháp phù hợp nhất cho bài toán Integer Sort trong phạm vi dữ liệu lớn của đề bài. Kết quả đạt được không chỉ đến từ độ phức tạp tuyến tính O(N ), mà còn phụ thuộc vào cách tổ chức bộ nhớ và các kỹ thuật tối ưu ở mức cài đặt.
Một số yếu tố quan trọng góp phần cải thiện hiệu năng bao gồm:
•	Giảm kích thước mảng đếm nhằm tăng khả năng tận dụng CPU Cache.
•	Sử dụng phép toán bitwise thay cho phép toán số học chi phí cao.
•	Tái sử dụng vùng nhớ trung gian để hạn chế cấp phát động.
•	Tối ưu tốc độ nhập/xuất dữ liệu hệ thống.
Từ đó có thể rút ra rằng trong các bài toán tối ưu hiệu năng, việc phân tích độ phức tạp lý thuyết chỉ phản ánh một phần hiệu quả thực tế của chương trình. Hiệu năng cuối cùng còn phụ thuộc đáng kể vào đặc điểm dữ liệu và cách triển khai thuật toán chi tiết.

II.	Lexicographic Sort
1.	THUẬT TOÁN TỐT NHẤT Ở LẦN CHẠY THỨ NHẤT

1.1	Thuật toán được chọn
•	Thuật toán được chọn là Heap Sort kết hợp kỹ thuật cấp phát bộ nhớ đệm liền kề để xử lí mảng con trỏ chuỗi
1.2	Ý tưởng cài đặt
Cách hoạt động chính: Thuật toán sử dụng cấu trúc Max-Heap để quản lý và sắp xếp phần tử. Quá trình chia làm 2 giai đoạn:
•	Xây dựng Max-Heap từ mảng đầu vào
•	Trích xuất phần tử lớn nhất ở gốc đưa về cuối mảng và khôi phục tính chất đống cho phần còn lại
Quy trình xử lý dữ liệu và các bước tối ưu quan trọng:
•	Xử lý dữ liệu: Thay vì lưu và di chuyển dữ liệu của từng chuỗi rất tốn chi phí, thuật toán đọc tất cả các chuỗi vào một bộ nhớ đệm liền kề duy nhất. Sau đó, một mảng các con trỏ sẽ lưu địa chỉ bắt đầu của mỗi chuỗi trong buffer
•	Thao tác hoán vị: Khi thuật toán Heap Sort thực hiện việc sắp xếp, nó chỉ tiến hành hoán đổi các con trỏ (kích thước 4 hoặc 8 bytes) thay vì phải sao chép toàn bộ nội dung của mảng ký tự
1.3	Các kỹ thuật tối ưu hóa đã sử dụng
a.	Tối ưu thuật toán
•	Khử đệ quy: Hàm heapify được chuyển hoàn toàn từ đệ quy sang vòng lặp while. Điều này giúp triệt tiêu chi phí gọi hàm và tránh lỗi tràn bộ nhớ ngăn xếp khi kích thước dữ liệu N lớn
•	Tránh hoán đổi thừa: Thêm điều kiện if (mx == i) break; để ngắt vòng lặp ngay lập tức khi mảng con đã thỏa mãn tính chất đống, giảm thiểu các phép so sánh dư thừa
b.	Tối ưu bộ nhớ
•	Sử dụng buffer tĩnh: Cấp phát một bộ đệm liền kề duy nhất                char* buffer = new char[n*101]; để chứa toàn bộ dữ liệu chuỗi đầu vào thay vì gọi new hoặc malloc riêng lẻ cho từng chuỗi. Kỹ thuật này triệt tiêu hoàn toàn chi phí hệ thống của việc cấp phát động nhiều lần
•	Tránh sao chép dữ liệu: Tái sử dụng việc so sánh qua con trỏ và hoán đổi con trỏ, không sử dụng strcpy hay std::string để tránh cấp phát vùng nhớ mới khi hoán đổi
c.	Tối ưu CPU
•	Tối ưu hóa bộ nhớ đệm bằng cách cài đặt toàn bộ các chuỗi nối tiếp nhau trong một buffer duy nhất, tỉ lệ lỗi trượt bộ nhớ đệm giảm xuống đáng kể khi CPU thực hiện đọc chuỗi liên tục để so sánh trong hàm strcmp
d.	Tối ưu nhấp/xuất
•	Fast I/O: Sử dụng hoàn toàn các hàm nhập xuất của ngôn ngữ C là scanf và printf thay vì cin và cout của C++. Kỹ thuật này nhanh hơn rất nhiều trong việc đọc/ghi chuỗi do không bị nghẽn bởi cơ chế đồng bộ của C++ streams
 
1.4	Phân tích độ phức tạp
Gọi N là số lượng chuỗi cần sắp xếp và L là chiều dài tối đa của một chuỗi
Trường hợp	Độ phức tạp	Giải thích
Best case	O(NlogN*L)	Heap Sort luôn đòi hỏi thao tác vun đống bất kể dữ liệu ban đầu. Mỗi phép so sánh chuỗi bằng strcmp mất tối đa O(L) thời gian
Average case	O(NlogN*L)	Tương tự trường hợp tốt nhất
Worst case	O(NlogN*L)	Khác với QuickSort có thể rớt xuống O(N^2), Heap Sort luôn đảm bảo số phép so sánh khống chế ở mức O(NlogN) trong mọi điều kiện phân bố của dữ liệu
Memory usage	O(N*L)	Thuật toán sử dụng một buffer phụ cỡ N x 101 bytes và một mảng con trỏ cỡ N x 8 bytes. Không sử dụng thêm bộ nhớ trên Call Stack do đã khử đệ quy








1.5	 Lý do thuật toán này tốt nhất ở lần 1
•	Đảm bảo thời gian chạy ổn định: Không giống như QuickSort thông thường sẽ bị giảm hiệu suất nghiêm trọng nếu gặp bộ test có nhiều phần tử trùng lặp hoặc đã được sắp xếp ngược. Heap Sort luôn duy trì hiệu suất O(NlogN) ổn định trong mọi trường hợp
•	Tối đa hóa lượng bộ nhớ: Sự khác biệt lớn nhất đến  từ kỹ thuật gom cụm bộ nhớ. Trong nhiều bài toán benchmart, nút thắt cổ chai thường không nằm ở thuật toán sắp xếp mà nằm ở chi phí gọi hệ điều hành cấp phát RAM cho hàng trăm ngàn chuỗi riêng biệt. Kỹ thuật cấp phát liền kề giải quyết triệt để nút thắt này
•	Giảm thiểu Cache Miss: Việc sử dụng vòng lặp trong heapify kết hợp với dữ liệu chuỗi nằm liền kề trên thanh RAM giúp phần cứng CPU tự động dự đoán dữ liệu tốt hơn hẳn so với việc duyệt cây đệ quy trên các vùng nhớ bị phân mảnh


2. Thuật toán tốt nhất ở lần chạy thứ hai
2.1	Ý tưởng cải tiến
Các vấn đề còn tồn tại ở lần 1:
•	Thuật toán Heap Sort ở lần 1 là thuật toán dựa trên so sánh. Nó yêu cầu độ phức tạp O(NlogN) phép so sánh chuỗi. Khi các chuỗi có chung nhiều tiền tốn, hàm strcmp phải duyệt lại từ đầu nhiều lần, gây lãng phí tính toán
•	Mặc dù đã tối ưu cấp phát bộ nhớ, cấu trúc cây nhị phân của Heap Sort khiến việc truy xuất các phần tử trên mảng nhảy cóc liên tục, dẫn đến Cache Locality kém
Những phần được tối ưu thêm ở lần 2:
•	Đổi hướng tiếp cận hoàn toàn: Chuyển từ “sắp xếp dựa trên so sánh” sang thuật toán “Sắp xếp phân phối” không dựa trên so sánh: MSD String Radix Sort
•	Xử lý chuỗi an toàn hơn bằng vector và string của C++ thay vì thao tác trên con trỏ thuần


2.2	Các tối ưu mới
a.	Tối ưu thuật toán
•	Sử dụng MSD Radix Sort: Thuật toán duyệt từng ký tự của chuỗi từ trái qua phải (từ ký tự quan trọng nhất). Các chuỗi được chia vào 28 bucket (26 chữ cái + 1 end-of-string + 1 bù trừ). Phương pháp này giúp loại bỏ hoàn toàn các phép so sánh chuỗi tổng thể. Thời gian chạy phụ thuộc vào tổng số ký tự cần kiểm tra, thường tiệm cận O(N*L) thay vì O(NlogN*L)
•	Tránh xử lý lại tiền tố chung: Khi một nhóm chuỗi được đưa vào chung một bucket (nghĩa là chúng có tiền tố giống nhau), vòng gọi đệ quy tiếp theo (pos + 1) chỉ bắt đầu so sánh từ vị trí khác biệt, bỏ qua toàn bộ phần tiền tố đã kiểm tra trước đó
b.	Tối ưu CPU/cache
•	Mảng đếm cục bộ: Mảng cnt và st có kích thước rất nhỏ được khởi tạo trên stack trong mỗi lệnh đệ quy. Điều này đảm bảo mảng đếm luôn nằm gọn trong L1 Cache của CPU, tốc độ truy cập gần như tức thời
•	Hoán đổi con trỏ ẩn: Thao tác a[i].swap(temp[i]) khai thác tính chất của string. Thay vì sao chép toàn bộ mảng ký tự sang mảng tạm, hàm swap chỉ hoán đổi con trỏ trỏ đến vùng nhớ chuỗi bên dưới (chỉ mất O(1)), tiết kiệm hàng triệu chu kỳ CPU
c.	Tối ưu bộ nhớ
•	Cấp phát mảng tạm một lần: Mảng phụ tmp(n) được khởi tạo ngay từ đầu trong main và truyền tham chiếu &temp xuyên suốt các lệnh gọi đệ quy. Kỹ thuật này tránh việc cấp phát/giải phóng bộ nhớ động ở từng độ sâu đệ quy của Radix Sort
•	Quản lý an toàn: Dùng vector quản lý mảng, triệt tiêu nguy cơ rò rỉ bộ nhớ hoặc lỗi con trỏ ngầm định thường gặp với mảng C-style
d.	Tối ưu I/O
•	Fast I/O C++: sử dụng ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); để vô hiệu hóa sự đồng bộ luồng giữa stdio của C và iostream của C+, đồng thời gỡ trói luồng nhập/xuất. Giúp tốc độ cin/cout tăng lên tiệm cận với scanf/printf




2.3	So sánh với lần 1

Thành phần	Lần 1	Lần 2
Thời gian chạy	O(NlogN*L)	Nhanh hơn về mặt lý thuyết ở số phép tính ký tự: O(N*L)
Bộ nhớ	Cấp phát tĩnh liền khối. Rất tối ưu	Cấp phát động phân mảnh (mỗi string là một vùng nhớ rời rạc). Hao tốn overhead
Cache locality	Kém (Heap nhảy cóc)	Khá (Truy cập mảng phụ tuần tự, mảng đếm cục bộ nhỏ)
Số phép so sánh	O(NlogN) phép so sánh chuỗi nguyên vẹn	Không có phép so sánh chuỗi. Chỉ tính chỉ số mảng bằng bảng mã ASCII

2.4	Kết quả đạt được
•	Mức cải thiện về hiệu năng: Về mặt tư duy giải thuật, tổng số phép toán logic được giảm đáng kể nhờ thuật toán tuyến tính
•	Các trường hợp chạy tốt nhất: Cực kỳ vượt trội khi bộ test gồm những chuỗi có độ dài lớn và chia sẻ chung nhiều tiền tố giống nhau
•	Các giới hạn còn tồn tại: Sự phân mảnh bộ nhớ: việc sử dụng vector<string> sẽ gọi hệ điều hành cấp phát bộ nhớ hàng vạn lần rời rạc (cho từng chuỗi), làm mất lợi thế cấp phát liền kề ở lần 1. Độ sâu đệ quy lớn: nếu chuỗi quá dài, chương trình gọi đệ quy rất sâu (tối đa bằng độ dài chuỗi dài nhất), có thể gây tràn Call Stack hoặc chậm trễ do Function Call Overhead




3.	Kết luận
   Thuật toán hiệu quả nhất: về cấu trúc thuật toán lõi, MSD String Radix Sort là phương pháp tối ưu nhất cho bài toán sắp xếp chuỗi từ điển so với các thuật toán dựa trên phép so sánh thông thường. Nó xử lý xuất sắc các trường hợp chuỗi có tiền tố chung dài
   Các kỹ thuật tối ưu quan trọng nhất:
•	Chuyển hướng từ sắp xếp so sánh sang sắp xếp đếm phân phối
•	Tái sử dụng mảng phụ trợ temp qua các lời gọi hàm đệ quy
•	Kỹ thuật “Zero-copy” trong C++ hiện đại thông qua std::string::swao() để đổi chỗ dữ liệu lớn
   Kinh nghiệm rút ra khi benchmark và tối ưu thuật toán: Sự chênh lệch giữa lý thuyết và thực tế hệ thống. Một thuật toán có độ phức tạp thời gian cực tốt (MSD Radix Sort) có thể không đạt hiệu suất tối đa nếu cấu trúc dữ liệu đi kèm không thân thiện với hệ thống quản lý bộ nhớ (liên tục cấp phát động).

III.	Length-aware Lexicographic String Sort
2. Thuật toán tốt nhất ở lần chạy thứ nhất
2.1. Thuật toán được chọn
Thuật toán được sử dụng ở lần chạy đầu tiên là Merge Sort cho chuỗi với tiêu chí sắp xếp:
1.	Ưu tiên độ dài chuỗi nhỏ hơn.
2.	Nếu độ dài bằng nhau thì so sánh từ điển (lexicographic).
Thuật toán sử dụng phương pháp chia để trị (divide and conquer), chia mảng thành hai nửa rồi tiến hành trộn lại theo thứ tự đã sắp xếp.
________________________________________
2.2. Ý tưởng cài đặt
Thuật toán hoạt động theo các bước:
1.	Chia mảng chuỗi thành hai nửa liên tục.
2.	Đệ quy sắp xếp từng nửa.
3.	Trộn hai mảng con đã sắp xếp bằng hàm merge.
Trong quá trình merge:
•	Tạo hai vector phụ l và r.
•	Sao chép dữ liệu từ mảng chính sang hai vector này.
•	So sánh từng phần tử bằng hàm compare.
•	Ghi kết quả trở lại mảng ban đầu.
Điều kiện so sánh:
•	Chuỗi có độ dài ngắn hơn sẽ đứng trước.
•	Nếu độ dài bằng nhau thì so sánh theo thứ tự từ điển.
________________________________________
2.3. Các kỹ thuật tối ưu hóa đã sử dụng
a) Tối ưu thuật toán
•	Sử dụng Merge Sort với độ phức tạp ổn định O(n log n).
•	Tách riêng hàm so sánh giúp dễ tối ưu và dễ mở rộng.
•	Giảm số lần xử lý điều kiện trong merge.
b) Tối ưu bộ nhớ
•	Dùng vector<string> để quản lý bộ nhớ tự động.
•	Chỉ tạo mảng phụ theo từng lần merge.
Tuy nhiên:
•	Mỗi lần merge đều cấp phát mới hai vector l và r.
•	Việc sao chép chuỗi gây tốn bộ nhớ và thời gian.
c) Tối ưu CPU
•	Sử dụng recursion depth cân bằng.
•	Truy cập dữ liệu tuần tự giúp cache locality tốt hơn Quick Sort trong nhiều trường hợp.
d) Tối ưu nhập/xuất
•	Sử dụng:
ios_base::sync_with_stdio(false);
cin.tie(NULL);


•	Tránh dùng endl để hạn chế flush buffer không cần thiết.
________________________________________
2.4. Phân tích độ phức tạp
Trường hợp	Độ phức tạp
Best case	O(n log n)
Average case	O(n log n)
Worst case	O(n log n)
Memory usage	O(n)
________________________________________
2.5. Lý do thuật toán này tốt nhất ở lần 1
Trong bài toán benchmark sắp xếp chuỗi theo:
1.	Độ dài chuỗi tăng dần.
2.	Nếu cùng độ dài thì sắp xếp lexicographic.
thuật toán Merge Sort được lựa chọn ở lần chạy đầu tiên vì có nhiều ưu điểm phù hợp với đặc điểm dữ liệu của đề bài.
a) Độ phức tạp ổn định
Merge Sort luôn có độ phức tạp:
•	O(n log n) ở mọi trường hợp.
•	Không bị rơi vào worst-case O(n²) như Quick Sort khi dữ liệu có phân bố xấu.
Điều này rất quan trọng trong benchmark vì bảng xếp hạng dựa trên test chạy chậm nhất.
________________________________________
b) Phù hợp với dữ liệu chuỗi
Trong đề bài, mỗi phép so sánh chuỗi có thể tốn nhiều thời gian do:
•	Độ dài chuỗi từ 10 đến 100 ký tự.
•	Có nhiều chuỗi có prefix giống nhau.
Merge Sort giúp giảm rủi ro phát sinh quá nhiều phép so sánh không cần thiết nhờ:
•	Chia dữ liệu cân bằng.
•	Số lần merge ổn định.
•	Không phụ thuộc vào pivot như Quick Sort.
________________________________________
c) Hoạt động tốt với dữ liệu lớn
Với số lượng dữ liệu lên tới:
n ≤ 10^4

Merge Sort vẫn đảm bảo:
•	Hiệu năng ổn định.
•	Không bị giảm mạnh tốc độ trên các test đặc biệt.
•	Dễ kiểm soát recursion depth.
________________________________________
d) Dễ cài đặt và đảm bảo tính đúng đắn
Phiên bản lần 1 ưu tiên:
•	Tính ổn định.
•	Dễ kiểm tra correctness.
•	Hạn chế bug trong benchmark.
Việc sử dụng:
vector<string>

và chia merge rõ ràng giúp thuật toán dễ debug và đảm bảo thứ tự sắp xếp chính xác theo yêu cầu đề bài.
________________________________________
e) Những hạn chế còn tồn tại
Mặc dù đạt hiệu năng khá tốt, phiên bản lần 1 vẫn còn một số điểm chưa tối ưu:
•	Cấp phát vector phụ liên tục trong mỗi lần merge.
•	Sao chép chuỗi nhiều lần gây tốn thời gian.
•	Chưa tận dụng move semantics.
•	Memory traffic còn cao.
Các hạn chế này trở thành mục tiêu tối ưu trong phiên bản lần chạy thứ hai.
4. Thuật toán tốt nhất ở lần chạy thứ hai
4.1. Ý tưởng cải tiến
Phiên bản thứ hai tiếp tục sử dụng Merge Sort nhưng được tối ưu mạnh hơn về bộ nhớ và thao tác dữ liệu.
Các vấn đề ở phiên bản 1:
•	Cấp phát vector phụ liên tục.
•	Sao chép chuỗi nhiều lần.
•	Memory overhead lớn.
Các cải tiến:
•	Tạo duy nhất một mảng temp.
•	Tái sử dụng buffer trong toàn bộ quá trình merge sort.
•	Dùng std::move() để giảm copy string.
•	Giảm số lần cấp phát động.
________________________________________
4.2. Các tối ưu mới
a) Tối ưu thuật toán
•	Giữ nguyên Merge Sort vì tính ổn định cao.
•	Giảm thao tác copy không cần thiết.
b) Tối ưu CPU/cache
•	Truy cập bộ nhớ liên tục hơn.
•	Tăng cache locality.
•	Giảm memory traffic.
c) Tối ưu bộ nhớ
•	Chỉ cấp phát temp một lần:
vector<string> temp(n);


•	Tái sử dụng buffer cho mọi lần merge.
•	Giảm allocation overhead.
d) Tối ưu I/O
Tiếp tục sử dụng fast I/O:
ios_base::sync_with_stdio(false);
cin.tie(NULL);

________________________________________
4.3. So sánh với lần 1
Thành phần	Lần 1	Lần 2
Thời gian chạy	Chậm hơn	Nhanh hơn
Bộ nhớ	Cấp phát nhiều	Tái sử dụng buffer
Cache locality	Trung bình	Tốt hơn
Số phép copy	Nhiều	Ít hơn
Move semantics	Không	Có
Memory traffic	Cao	Thấp hơn
________________________________________
4.4. Kết quả đạt được
Phiên bản thứ hai đạt được nhiều cải thiện rõ rệt:
•	Giảm thời gian chạy trên dữ liệu lớn.
•	Giảm số lần cấp phát động.
•	Giảm copy string.
•	Tăng hiệu quả cache.
Đặc biệt hiệu quả với:
•	Bộ test nhiều chuỗi dài.
•	Bộ test có prefix giống nhau.
•	Dữ liệu kích thước lớn.
Tuy nhiên:
•	Thuật toán vẫn cần bộ nhớ phụ O(n).
•	Chi phí so sánh chuỗi vẫn còn lớn khi prefix dài.
________________________________________
5. Kết luận
Qua quá trình benchmark và tối ưu, phiên bản Merge Sort lần 2 cho hiệu năng tốt hơn đáng kể nhờ:
•	Tái sử dụng buffer.
•	Giảm cấp phát động.
•	Sử dụng std::move.
•	Tăng cache locality.
Các kinh nghiệm rút ra:
•	Bộ nhớ ảnh hưởng rất lớn tới hiệu năng.
•	Giảm allocation giúp tăng tốc đáng kể.
•	Với dữ liệu chuỗi, chi phí compare và copy rất quan trọng.
•	Tối ưu memory access đôi khi hiệu quả hơn thay đổi thuật toán.
Phiên bản lần 2 là phiên bản hiệu quả nhất trong các hướng cài đặt đã thử nghiệm.

IV.	Thiết kế bộ sinh test
3.1. Chiến lược cấu hình dữ liệu
•	Công cụ sinh: Bộ sinh số ngẫu nhiên chuẩn std::mt19937 kết hợp hằng số seed cố định 2026 để đảm bảo tính đồng nhất trên mọi máy chấm.
•	Kích thước mẫu: Đẩy lên mức biên tối hạn của đề bài: N = 100.000 (đối với int và strlexi) và N = 10.000 (đối với strlenlexi).
3.2. Cấu trúc hệ thống bộ test đối kháng cho Bài A (int)
•	Test 1 (Random Range): Sinh ngẫu nhiên phân bổ đều trên toàn dải [-2^31, 2^31 - 1] nhằm tấn công các cấu trúc Radix Sort 16-bit thiếu tối ưu cache.
•	Test 2 (Reverse Sorted): Dãy số giảm dần tuyến tính tuyệt đối từ 100.000 về 1 nhằm phá hủy Timsort hoặc Insertion Sort cài tay.
•	Test 3 (Extreme Alternating Values): Luân phiên đan xen liên tục giữa -2147483648 và 2147483647 để đánh bẫy các thuật toán Quicksort phân vùng 2 đường.
•	Test 4 (All Equal): Toàn bộ mảng là một hằng số cố định nhằm triệt hạ Quicksort thiếu kỹ thuật phân hoạch 3 đường.
•	Test 5 (Multiples of 65536): Toàn bộ mảng là bội số chính xác của hằng số 65536 (2^16) để tạo bẫy xung đột thùng chứa đối với Radix Sort 16-bit.
3.3. Cấu trúc hệ thống bộ test đối kháng cho Bài B (strlexi)
•	Test 1 (Random Generation): Sinh chuỗi ký tự thường ngẫu nhiên với độ dài biến thiên trong khoảng từ 10 đến 100 ký tự.
•	Test 2 (Deep Prefix Attack): Tạo ra 100.000 chuỗi có tiền tố dài 99 ký tự giống hệt nhau ('a'), chỉ khác biệt duy nhất ở ký tự cuối cùng thứ 100 để ép Multi-key Quicksort đệ quy sâu chạm đáy.
•	Test 3 (Sorted Base): Sinh dãy chuỗi số hóa có đệm ký tự 'b' phía trước để lấp đầy độ dài 100 ký tự, sau đó tiến hành sắp xếp tăng dần nhằm đánh bẫy cơ chế chọn pivot biên.
•	Test 4 (Reverse Sorted / Anti-Median-of-Three): Sử dụng dãy chuỗi số hóa đệm kí tự 'b' tương tự Test 3 nhưng được đảo ngược hoàn toàn thứ tự từ điển để phá hủy cơ chế chọn pivot trung vị.
•	Test 5 (All Identical Matrix): Toàn bộ 100.000 chuỗi đều mang một giá trị hằng số chứa đúng 100 ký tự 'm' nhằm làm suy biến các thuật toán phân đôi chuỗi thông thường.
3.4. Cấu trúc hệ thống bộ test đối kháng cho Bài C (strlenlexi)
•	Test 1 (Ascending Length Run): Sinh các chuỗi ký tự lặp lại có độ dài tăng dần tuần hoàn từ 10 đến 100 ký tự.
•	Test 2 (LSD Inefficiency Trap): Sinh dãy chuỗi có cùng độ dài cố định là 100 ký tự, trong đó 95 ký tự đầu là chuỗi ký tự cố định 's' kết hợp phần đuôi số hóa để vô hiệu hóa hiệu năng quét ngược của LSD Radix Sort chuỗi.
•	Test 3 (All Minimum Length Matrix): Sinh mảng 10.000 chuỗi đều đạt độ dài ngắn nhất ở mức biên tối thiểu là cố định đúng 10 ký tự.
•	Test 4 (Length Divergence / Numeric Trap): Tạo cấu trúc dữ liệu đan xen luân phiên liên tục giữa một chuỗi toàn ký tự số '9' (dài 15) và một chuỗi toàn ký tự số '1' (dài 16) nhằm bẫy logic phân loại sai quy chuẩn.
•	Test 5 (Random Mix): Sinh chuỗi ngẫu nhiên hoàn toàn cả về nội dung ký tự lẫn độ dài chuỗi (biến thiên tự do trong dải từ 10 đến 100) để kiểm tra giới hạn thời gian chạy 1 giây.
3.5. Cơ chế tác động làm tăng thời gian chạy của bộ test
•	Với bài int (test005.in): Do dữ liệu là bội số của 2^16, toàn bộ phần tử đều có 16 bit thấp bằng 0. Tại Pass 1, tất cả 100.000 số bị dồn cục vào ô nhớ duy nhất count[0], triệt tiêu hoàn toàn tính phân tán dữ liệu.
•	Với bài strlexi (test002.in): Ép thuật toán Multi-key Quicksort phải gọi đệ quy sâu liên tục chạm đáy 100 tầng hệ thống, đồng thời ép hàm Insertion Sort nội bộ phải so sánh tuần tự toàn bộ 100 ký tự mới phân định được lớn bé.
•	Với bài strlenlexi (test004.in): Nếu chương trình của đối thủ thực hiện phép so sánh chuỗi từ điển mặc định hoặc lỡ ép kiểu chuỗi sang dạng số, chuỗi toàn số 9 (dài 15) sẽ bị xếp đứng sau chuỗi toàn số 1 (dài 16) do mã ASCII của ký tự '9' lớn hơn '1', lập tức kích hoạt lỗi Wrong Answer.


