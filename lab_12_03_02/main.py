import sys
from PyQt6 import QtWidgets
import interface
import ctypes

lib = ctypes.CDLL('./libfunc.dll')

# void generate_simple(int n, int *arr)
_generate_simple = lib.generate_simple
_generate_simple.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_generate_simple.restype = None

# int modif_array(int *src, int n, int *dst, int m, int x)
_modif_array = lib.modif_array
_modif_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
_modif_array.restype = ctypes.c_int

def toString(lst):
    s = ""
    for i in range(len(lst)):
        s += str(lst[i]) + " "
    
    return s

class MainWindow(QtWidgets.QMainWindow, interface.Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.button.clicked.connect(self.operate)
        self.chooseBox.currentIndexChanged.connect(self.changeLabel)

    def operate(self):
        if (self.chooseBox.currentIndex() == 0):
            try:
                num = int(self.input.text())
                if (num > 0):
                    # Первая функция
                    ans = self.generate_simple(num)

                    ans = toString(ans)
                    self.answer.setText(str(ans))
                    self.statusbar.showMessage("Выполнено!")
                else:
                    self.statusbar.showMessage("Введите натуральное число")
            except ValueError:
                self.statusbar.showMessage("Введите натуральное число")
        else:
            try:
                lst = list(map(int, self.input.text().split()))
                x = lst[0]
                lst = lst[1:]
                # Вторая функция
                ans = self.modif_array(lst, x)

                ans = toString(ans)
                self.answer.setText(ans)
                self.statusbar.showMessage("Выполнено!")
            except ValueError:
                self.statusbar.showMessage("Введите массив целых положительных числел")

    def changeLabel(self, i):
        if i == 0:
            self.label_input.setText("Введите число:")
        else:
            self.label_input.setText("Введите число и массив:")
    

    def generate_simple(self, n):
        arr = (ctypes.c_int * n)()
        _generate_simple(n, arr)
        
        return list(arr)

    def modif_array(self, arr, x):
        n = len(arr)
        arr = (ctypes.c_int * n)(*arr)
        m = ctypes.c_int(0)
        
        rc = _modif_array(arr, n, None, m, x)
        if rc > 0:
            res = (ctypes.c_int * rc)()
            
            rc = _modif_array(arr, n, res, rc, x)
            
            return list(res)	
        else:
            return list()

def main():
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    app.exec()


if __name__ == '__main__':
    main()
