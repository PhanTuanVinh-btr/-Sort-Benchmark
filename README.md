# 📊 BÁO CÁO CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT

**Môn học:** Cấu trúc dữ liệu và giải thuật

**Thời gian học:** Học kỳ II năm học 2025 - 2026

### 👥 Danh sách sinh viên

| STT | Họ và tên | MSSV |
| --- | --- | --- |
| 1 | Nguyễn Đoàn Như Ý | 25120475 |
| 2 | Nguyễn Minh Quyến | 25120427 |
| 3 | Phan Tuấn Vinh | 25120472 |

---

## 📑 Mục lục

1. [I. Integer Sort](https://www.google.com/search?q=%23i-integer-sort)
* [1. Thuật toán tốt nhất ở lần chạy thứ nhất](https://www.google.com/search?q=%231-thu%E1%BA%ADt-to%C3%A1n-t%E1%BB%91t-nh%E1%BA%A5t-%E1%BB%9F-l%E1%BA%A7n-ch%E1%BA%A1y-th%E1%BB%A9-nh%E1%BA%A5t)
* [2. Cải tiến thuật toán (Lần chạy thứ hai)](https://www.google.com/search?q=%232-c%E1%BA%A3i-ti%E1%BA%BFn-thu%E1%BA%ADt-to%C3%A1n-l%E1%BA%A7n-ch%E1%BA%A1y-th%E1%BB%A9-hai)
* [3. Kết luận](https://www.google.com/search?q=%233-k%E1%BA%BFt-lu%E1%BA%ADn)


2. [II. Lexicographic Sort](https://www.google.com/search?q=%23ii-lexicographic-sort)
* [1. Thuật toán tốt nhất ở lần chạy thứ nhất](https://www.google.com/search?q=%231-thu%E1%BA%ADt-to%C3%A1n-t%E1%BB%91t-nh%E1%BA%A5t-%E1%BB%9F-l%E1%BA%A7n-ch%E1%BA%A1y-th%E1%BB%A9-nh%E1%BA%A5t-1)
* [2. Thuật toán tốt nhất ở lần chạy thứ hai](https://www.google.com/search?q=%232-thu%E1%BA%ADt-to%C3%A1n-t%E1%BB%91t-nh%E1%BA%A5t-%E1%BB%9F-l%E1%BA%A7n-ch%E1%BA%A1y-th%E1%BB%A9-hai)
* [3. Kết luận](https://www.google.com/search?q=%233-k%E1%BA%BFt-lu%E1%BA%ADn-1)


3. [III. Length-aware Lexicographic String Sort](https://www.google.com/search?q=%23iii-length-aware-lexicographic-string-sort)
* [1. Thuật toán tốt nhất ở lần chạy thứ nhất](https://www.google.com/search?q=%231-thu%E1%BA%ADt-to%C3%A1n-t%E1%BB%91t-nh%E1%BA%A5t-%E1%BB%9F-l%E1%BA%A7n-ch%E1%BA%A1y-th%E1%BB%A9-nh%E1%BA%A5t-2)
* [2. Thuật toán tốt nhất ở lần chạy thứ hai](https://www.google.com/search?q=%232-thu%E1%BA%ADt-to%C3%A1n-t%E1%BB%91t-nh%E1%BA%A5t-%E1%BB%9F-l%E1%BA%A7n-ch%E1%BA%A1y-th%E1%BB%A9-hai-1)
* [3. Kết luận](https://www.google.com/search?q=%233-k%E1%BA%BFt-lu%E1%BA%ADn-2)


4. [IV. Thiết kế bộ sinh test](https://www.google.com/search?q=%23iv-thi%E1%BA%BFt-k%E1%BA%BF-b%E1%BB%99-sinh-test)

---

## I. Integer Sort

### 1. Thuật toán tốt nhất ở lần chạy thứ nhất

#### 1.1 Thuật toán được lựa chọn

Trong lần chạy đầu tiên, thuật toán được lựa chọn để giải quyết bài toán Integer Sort là **LSD Radix Sort 16-bit** với cơ số:


$$2^{16} = 65536$$

Mục tiêu chính của phương pháp này là giảm số lượt xử lý dữ liệu đối với số nguyên 32-bit. Thay vì phải thực hiện nhiều lần phân phối như Radix Sort cơ số nhỏ, việc sử dụng cơ số $2^{16}$ cho phép hoàn thành quá trình sắp xếp chỉ sau 2 lượt quét dữ liệu (Pass).

So với các thuật toán sắp xếp dựa trên phép so sánh như Quicksort hoặc Mergesort, Radix Sort phù hợp hơn với bài toán sắp xếp số nguyên quy mô lớn nhờ đặc tính xử lý tuyến tính.

#### 1.2 Ý tưởng cài đặt

Thuật toán được xây dựng dựa trên nguyên lý **Least Significant Digit (LSD)**, nghĩa là xử lý dữ liệu từ nhóm bit thấp đến nhóm bit cao. Với kiểu dữ liệu số nguyên 32-bit, mỗi giá trị được chia thành hai nhóm 16-bit, tương ứng với hai lượt xử lý.

* **Bước 1: Đồng bộ miền giá trị**
Do dữ liệu đầu vào bao gồm cả số âm và số dương, việc sắp xếp trực tiếp theo bit có thể gây sai lệch thứ tự. Để khắc phục, chương trình sử dụng phép biến đổi:
```cpp
x ^ 0x80000000

```


Phép toán này giúp chuyển miền giá trị: $[-2^{31}, 2^{31} - 1]$ thành: $[0, 2^{32} - 1]$ nhằm đưa toàn bộ dữ liệu về dạng không dấu, từ đó đảm bảo thứ tự sắp xếp được bảo toàn.
* **Bước 2: Xử lý 16 bit thấp**
Ở Pass đầu tiên, thuật toán trích xuất 16 bit thấp của từng phần tử bằng biểu thức:
```cpp
(arr[i] >> 0) & 0xFFFF

```


Sau đó thực hiện: Đếm số lần xuất hiện của từng giá trị, tính tổng tích lũy (prefix sum), và phân phối phần tử sang mảng trung gian `temp`.
* **Bước 3: Xử lý 16 bit cao**
Ở Pass thứ hai, thuật toán tiếp tục xử lý nhóm bit cao bằng:
```cpp
(arr[i] >> 16) & 0xFFFF

```


Quy trình đếm và phân phối được thực hiện tương tự. Để hạn chế chi phí sao chép mảng sau mỗi Pass, chương trình sử dụng:
```cpp
arr.swap(temp);

```


Phép toán này chỉ thực hiện hoán đổi vùng quản lý bộ nhớ của `vector`, giúp giảm chi phí xử lý trên tập dữ liệu lớn.

#### 1.3 Các kỹ thuật tối ưu hóa đã sử dụng

* **a) Tối ưu thuật toán (XOR Transformation):** Thay vì xử lý riêng số âm và số dương bằng các nhánh điều kiện (`if-else`), chương trình sử dụng phép XOR với `0x80000000` để chuẩn hóa.
* **b) Tối ưu bộ nhớ (Tái sử dụng mảng phụ):** Mảng trung gian `temp` được cấp phát một lần với kích thước $N$ trước khi thuật toán bắt đầu và được tái sử dụng.
* **c) Tối ưu CPU (Sử dụng phép toán bitwise):** Các toán tử dịch bit (`>>`) và toán tử AND (`&`) được sử dụng thay cho phép chia (`/`) hoặc chia dư (`%`).
* **d) Tối ưu nhập/xuất:** Vô hiệu hóa đồng bộ luồng và giải phóng liên kết đệm. Ký tự xuống dòng `\n` được ưu tiên thay cho `endl` nhằm tránh thao tác flush buffer.

#### 1.4 Phân tích độ phức tạp

Do số lượt xử lý được cố định ở mức 2, độ phức tạp của thuật toán gần như không phụ thuộc vào phân bố dữ liệu đầu vào.

* **Best Case:** $\mathcal{O}(2 \cdot (N + 65536)) \Rightarrow \mathcal{O}(N)$
* **Average Case:** $\mathcal{O}(2 \cdot (N + 65536)) \Rightarrow \mathcal{O}(N)$
* **Worst Case:** $\mathcal{O}(2 \cdot (N + 65536)) \Rightarrow \mathcal{O}(N)$
* **Bộ nhớ sử dụng:** $\mathcal{O}(N + 65536)$ bao gồm mảng phụ `temp` kích thước $N$ và mảng đếm `count` gồm $65536$ phần tử.

#### 1.5 Lý do thuật toán này hiệu quả nhất ở lần chạy thứ nhất

1. **Số lượt xử lý thấp:** Chỉ cần đúng 2 Pass.
2. **Hiệu năng tuyến tính:** Hoàn toàn phù hợp với tập dữ liệu lớn như $N = 10^5$.
3. **Ổn định với nhiều kiểu dữ liệu:** Thời gian thực thi gần như không thay đổi với mọi cấu trúc dữ liệu đầu vào.

---

### 2. Cải tiến thuật toán (Lần chạy thứ hai)

#### 2.1 Ý tưởng cải tiến

Mặc dù phiên bản Radix Sort 16-bit có số lượt xử lý ít, kích thước lớn của mảng `count` ($65536 \times 4 \text{ bytes} \approx 256 \text{ KB}$) vượt quá dung lượng L1 Data Cache của phần lớn CPU.

Thuật toán được điều chỉnh sang **LSD Radix Sort 8-bit** với cơ số:


$$2^8 = 256$$


Không gian chiếm dụng giảm mạnh xuống còn: $256 \times 4 \text{ bytes} = 1 \text{ KB}$. Mặc dù số Pass tăng từ 2 lên 4, mảng đếm nhỏ hơn giúp tối ưu hóa băng thông luồng dữ liệu.

#### 2.2 Các tối ưu mới

* **Tối ưu bộ nhớ:** Sử dụng mảng tĩnh thô `int count[256]` để loại bỏ chi phí quản lý vùng Heap.
* **Tối ưu cache:** Tăng cường tính cục bộ dữ liệu (Cache Locality) và hạn chế Cache Miss.
* **Tái sử dụng bộ nhớ:** Mảng `temp` duy trì cấp phát duy nhất một lần.

#### 2.3 So sánh benchmark

| Thành phần | Lần 1 (Radix Sort 16-bit) | Lần 2 (Radix Sort 8-bit) 🏆 |
| --- | --- | --- |
| **Số Pass** | 2 | 4 |
| **Bộ nhớ mảng đếm** | $\approx 256$ KB | **$\approx 1$ KB** |
| **Độ phức tạp** | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ |

> 💡 **Nhận xét:** Việc giảm kích thước mảng đếm giúp khả năng tận dụng CPU Cache tăng vọt. Thuật toán **Radix Sort 8-bit** cho kết quả thời gian thực thi ổn định và vượt trội hơn trên các bộ test khắc nghiệt, xứng đáng là lựa chọn tốt nhất.

#### 2.4 Kết quả đạt được

Sau khi tối ưu, phiên bản Radix Sort 8-bit cho kết quả ổn định hơn. Việc giảm chi phí truy cập bộ nhớ RAM vật lý bù đắp hoàn toàn cho việc tăng số lượt xử lý. Tuy nhiên, thuật toán vẫn là Out-of-place (cần mảng `temp` $\mathcal{O}(N)$).

---

### 3. Kết luận

Qua quá trình benchmark, **LSD Radix Sort 8-bit kết hợp biến đổi bit dấu bằng XOR** là giải pháp phù hợp nhất. Hiệu năng cuối cùng không chỉ đến từ độ phức tạp lý thuyết $\mathcal{O}(N)$ mà còn phụ thuộc đáng kể vào:

* Tận dụng tối đa CPU Cache nhờ thu gọn mảng đếm.
* Kỹ thuật Bitwise thay thế toán học.
* Hạn chế cấp phát động (Dynamic Allocation).

---

## II. Lexicographic Sort

### 1. Thuật toán tốt nhất ở lần chạy thứ nhất

#### 1.1 Thuật toán được chọn

Thuật toán được chọn là **Heap Sort** kết hợp kỹ thuật cấp phát bộ nhớ đệm liền kề để xử lí mảng con trỏ chuỗi.

#### 1.2 Ý tưởng cài đặt

Sử dụng cấu trúc Max-Heap chia làm 2 giai đoạn:

1. Xây dựng Max-Heap từ mảng đầu vào.
2. Trích xuất phần tử lớn nhất ở gốc đưa về cuối mảng và khôi phục tính chất đống.

**Quy trình xử lý dữ liệu:**

* **Xử lý dữ liệu:** Đọc tất cả các chuỗi vào một bộ nhớ đệm liền kề duy nhất. Một mảng các con trỏ sẽ lưu địa chỉ bắt đầu của mỗi chuỗi trong buffer.
* **Thao tác hoán vị:** Chỉ tiến hành hoán đổi các con trỏ (4-8 bytes) thay vì sao chép nội dung chuỗi.

#### 1.3 Các kỹ thuật tối ưu hóa đã sử dụng

* **Khử đệ quy:** Hàm `heapify` được chuyển hoàn toàn sang vòng lặp `while`.
* **Tránh hoán đổi thừa:** Thêm điều kiện ngắt sớm:
```cpp
if (mx == i) break;

```


* **Sử dụng buffer tĩnh:** ```cpp
char* buffer = new char[n * 101];
```

```


* **Tối ưu I/O:** Sử dụng hoàn toàn `scanf` và `printf` thay vì `cin`/`cout`.

#### 1.4 Phân tích độ phức tạp

Gọi $N$ là số lượng chuỗi và $L$ là chiều dài tối đa của một chuỗi.

| Trường hợp | Độ phức tạp | Giải thích |
| --- | --- | --- |
| **Best case** | $\mathcal{O}(N \log N \cdot L)$ | Heap Sort luôn đòi hỏi thao tác vun đống. Mỗi phép `strcmp` mất $\mathcal{O}(L)$. |
| **Average case** | $\mathcal{O}(N \log N \cdot L)$ | Tương tự tốt nhất. |
| **Worst case** | $\mathcal{O}(N \log N \cdot L)$ | Không bị suy biến xuống $\mathcal{O}(N^2)$ như QuickSort. |
| **Memory usage** | $\mathcal{O}(N \cdot L)$ | Dùng buffer phụ $N \times 101$ bytes và mảng con trỏ. |

#### 1.5 Lý do thuật toán này tốt nhất ở lần 1

1. **Đảm bảo thời gian chạy ổn định:** Không bị suy giảm hiệu suất nếu test có phần tử trùng lặp.
2. **Tối đa hóa lượng bộ nhớ (Zero-allocation per string):** Giải quyết nút thắt cổ chai của việc gọi hệ điều hành cấp phát RAM hàng trăm ngàn lần.
3. **Giảm thiểu Cache Miss:** Dữ liệu chuỗi nằm liền kề trên thanh RAM.

---

### 2. Thuật toán tốt nhất ở lần chạy thứ hai

#### 2.1 Ý tưởng cải tiến

Chuyển từ "sắp xếp dựa trên so sánh" sang "sắp xếp phân phối": **MSD String Radix Sort**. Xử lý chuỗi an toàn hơn bằng `vector` và `string` của C++.

#### 2.2 Các tối ưu mới

* **Tránh xử lý lại tiền tố chung:** Đệ quy ở vị trí `pos + 1` bỏ qua toàn bộ phần tiền tố đã kiểm tra.
* **Mảng đếm cục bộ:** Mảng `cnt` và `st` rất nhỏ, khởi tạo trên stack $\Rightarrow$ Nằm gọn trong L1 Cache.
* **Hoán đổi con trỏ ẩn:** Sử dụng phương thức hoán đổi nội tại mất $\mathcal{O}(1)$:
```cpp
a[i].swap(temp[i]);

```


* **Fast I/O C++:**
```cpp
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

```



#### 2.3 So sánh với lần 1

| Thành phần | Lần 1 (Heap Sort) | Lần 2 (MSD Radix Sort) 🏆 |
| --- | --- | --- |
| **Thời gian chạy** | $\mathcal{O}(N \log N \cdot L)$ | Nhanh hơn: **$\mathcal{O}(N \cdot L)$** |
| **Cache locality** | Kém (Nhảy cóc) | **Khá** (Truy cập tuần tự) |
| **Số phép so sánh** | $\mathcal{O}(N \log N)$ phép so sánh chuỗi | **Không có phép so sánh chuỗi** |

> 💡 **Nhận xét:** MSD Radix Sort giải quyết triệt để vấn đề so sánh lại các tiền tố (prefix) chung, mang lại tốc độ đột phá về mặt tính toán logic.

#### 2.4 Kết quả đạt được

* **Ưu điểm:** Cực kỳ vượt trội khi bộ test gồm những chuỗi có độ dài lớn và chia sẻ chung nhiều tiền tố.
* **Hạn chế:** Sự phân mảnh bộ nhớ khi dùng `vector<string>` và Function Call Overhead nếu chuỗi quá dài.

---

### 3. Kết luận

Về cấu trúc thuật toán lõi, **MSD String Radix Sort** là phương pháp tối ưu nhất cho bài toán sắp xếp chuỗi từ điển. Kỹ thuật “Zero-copy” thông qua `std::string::swap()` là chìa khóa để xử lý khối lượng dữ liệu lớn mà không bị nghẽn Memory Traffic.

---

## III. Length-aware Lexicographic String Sort

### 1. Thuật toán tốt nhất ở lần chạy thứ nhất

#### 1.1 Thuật toán được chọn

Thuật toán được sử dụng là **Merge Sort** với tiêu chí:

1. Ưu tiên độ dài chuỗi nhỏ hơn.
2. Nếu độ dài bằng nhau thì so sánh từ điển (lexicographic).

#### 1.2 Ý tưởng cài đặt

Áp dụng **Divide and Conquer**, chia mảng và trộn lại (`merge`). Điều kiện so sánh (Compare function):

* Chuỗi ngắn hơn đứng trước.
* Độ dài bằng nhau $\Rightarrow$ So sánh thứ tự từ điển.

#### 1.3 Các kỹ thuật tối ưu hóa đã sử dụng

* **Tối ưu thuật toán:** Tách riêng hàm so sánh, giảm số lần xử lý điều kiện trong hàm merge.
* **Tối ưu CPU:** Cân bằng recursion depth, truy cập bộ nhớ tuần tự (Cache locality tốt hơn Quick Sort).
* **Hạn chế:** Mỗi lần merge đều cấp phát mới 2 vector `l` và `r`, gây tốn bộ nhớ và thời gian sao chép.

#### 1.4 Phân tích độ phức tạp

| Trường hợp | Độ phức tạp |
| --- | --- |
| **Best case** | $\mathcal{O}(N \log N)$ |
| **Average case** | $\mathcal{O}(N \log N)$ |
| **Worst case** | $\mathcal{O}(N \log N)$ |
| **Memory usage** | $\mathcal{O}(N)$ |

#### 1.5 Lý do thuật toán này tốt nhất ở lần 1

Merge Sort đảm bảo tính ổn định tuyệt đối ($\mathcal{O}(N \log N)$), không bị suy biến. Đồng thời, chia dữ liệu cân bằng giúp hạn chế số phép so sánh dư thừa khi xử lý các chuỗi có prefix giống nhau.

---

### 2. Thuật toán tốt nhất ở lần chạy thứ hai

#### 2.1 Ý tưởng cải tiến

Vấn đề cốt lõi của phiên bản 1 là **Memory Overhead**. Các cải tiến tập trung vào việc quản lý vùng nhớ đệm:

* Tạo duy nhất một mảng `temp`.
* Tái sử dụng buffer.
* Dùng `std::move()` để giảm copy.

#### 2.2 Các tối ưu mới

* **Chỉ cấp phát temp một lần:**
```cpp
vector<string> temp(n);

```


* **Tối ưu bộ nhớ:** Giảm allocation overhead, tái sử dụng buffer cho mọi lần đệ quy.

#### 2.3 So sánh hiệu năng

| Thành phần | Lần 1 (Merge Sort Cơ bản) | Lần 2 (Merge Sort Tối ưu Memory) 🏆 |
| --- | --- | --- |
| **Bộ nhớ** | Cấp phát liên tục | **Tái sử dụng buffer** |
| **Số phép copy** | Rất nhiều | **Ít hơn (Dùng `std::move`)** |
| **Memory traffic** | Cao | **Thấp** |

> 💡 **Nhận xét:** Chỉ với việc tái sử dụng bộ nhớ và áp dụng Move Semantics của C++ hiện đại, thuật toán đã loại bỏ hoàn toàn các nút thắt cổ chai về hệ thống cấp phát RAM.

#### 2.4 Kết quả đạt được

Thời gian chạy trên tập dữ liệu lớn giảm đáng kể. Hiệu quả đặc biệt rõ rệt với bộ test chứa nhiều chuỗi dài có prefix giống nhau.

---

### 3. Kết luận

Với bài toán có chi phí `compare` và `copy` đắt đỏ như String Sort, việc tối ưu **Memory Access (Truy cập bộ nhớ)** đôi khi mang lại hiệu quả cao hơn cả việc thay đổi kiến trúc thuật toán lõi.

---

## IV. Thiết kế bộ sinh test

### 1. Chiến lược cấu hình dữ liệu

* **Công cụ sinh:** `std::mt19937` kết hợp hằng số seed cố định `2026` để đảm bảo đồng nhất trên mọi máy chấm.
* **Kích thước mẫu:** Biên tối hạn $N = 100.000$ (cho `int`, `strlexi`) và $N = 10.000$ (cho `strlenlexi`).

### 2. Cấu trúc hệ thống bộ test đối kháng cho Bài A (int)

* **Test 1 (Random Range):** Sinh ngẫu nhiên phân bổ đều trên $[-2^{31}, 2^{31} - 1]$.
* **Test 2 (Reverse Sorted):** Giảm dần tuyến tính từ $100.000$ về $1$ $\Rightarrow$ Phá hủy Timsort / Insertion Sort.
* **Test 3 (Extreme Alternating Values):** Đan xen $-2147483648$ và $2147483647$ $\Rightarrow$ Bẫy Quicksort 2 đường.
* **Test 4 (All Equal):** Mảng toàn hằng số $\Rightarrow$ Triệt hạ Quicksort thiếu phân hoạch 3 đường.
* **Test 5 (Multiples of 65536):** Toàn bộ mảng là bội số của $2^{16}$ $\Rightarrow$ Bẫy xung đột thùng chứa cho Radix Sort 16-bit.

### 3. Cấu trúc hệ thống bộ test đối kháng cho Bài B (strlexi)

* **Test 1:** Sinh ngẫu nhiên độ dài 10 - 100 ký tự.
* **Test 2 (Deep Prefix Attack):** $100.000$ chuỗi có 99 ký tự 'a' giống nhau, chỉ khác ký tự thứ 100 $\Rightarrow$ Ép Multi-key Quicksort đệ quy chạm đáy.
* **Test 3 & 4 (Sorted/Reverse Sorted Base):** Lấp đầy độ dài bằng ký tự 'b', bẫy cơ chế chọn pivot biên và pivot trung vị.
* **Test 5 (All Identical Matrix):** Toàn bộ chuỗi chứa 100 ký tự 'm' $\Rightarrow$ Suy biến các thuật toán phân đôi chuỗi.

### 4. Cấu trúc hệ thống bộ test đối kháng cho Bài C (strlenlexi)

* **Test 1 (Ascending Length Run):** Chiều dài tăng dần tuần hoàn.
* **Test 2 (LSD Inefficiency Trap):** 95 ký tự đầu cố định 's', đuôi số hóa $\Rightarrow$ Vô hiệu hóa Radix Sort LSD.
* **Test 3 (All Minimum Length):** 10.000 chuỗi cố định 10 ký tự.
* **Test 4 (Length Divergence / Numeric Trap):** Đan xen chuỗi toàn số '9' (dài 15) và số '1' (dài 16) $\Rightarrow$ Bẫy lỗi Wrong Answer nếu ép kiểu sai.
* **Test 5 (Random Mix):** Sinh ngẫu nhiên hoàn toàn kiểm tra giới hạn 1 giây.

### 5. Cơ chế tác động làm tăng thời gian chạy

* **Bài int (test005.in):** Mọi phần tử đều có 16 bit thấp bằng 0 $\Rightarrow$ Tại Pass 1, 100.000 số bị dồn cục vào `count[0]`.
* **Bài strlexi (test002.in):** Ép Multi-key Quicksort gọi đệ quy 100 tầng và ép Insertion Sort phải so sánh tuần tự toàn bộ 100 ký tự.
* **Bài strlenlexi (test004.in):** Đánh lừa tư duy lập trình bằng mã ASCII. Ký tự '9' lớn hơn '1', nếu không kiểm tra chuẩn độ dài sẽ lập tức Wrong Answer.
