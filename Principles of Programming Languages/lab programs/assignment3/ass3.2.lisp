;ANANT SHARMA
;2015KUCP1018
;Write a program in LISP to perform swapping on array in following manner: 2. swap first and last element, second and second last element and so on.

(defvar x 10)
(setf arr (make-array x))
(dotimes (i x)
    (setf (aref arr i) (+ -100 (random 200)) )
)
(write "Original Random Array")
(print arr)

(defvar tmp 0)
(defvar y (floor x 2))
(dotimes (i y)
    (setq tmp (aref arr (- (1- x) i) ) )
    (setf (aref arr (- (1- x) i) ) (aref arr i) )
    (setf (aref arr i) tmp )
)
(print "Array after swapping 1 to n,2 to n-2, .. elements")
(print arr)
