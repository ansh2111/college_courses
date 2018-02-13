;fibonacci series
(defvar x 0)
(defvar y 1)

(defvar tmp 0)

(dotimes (n 11)

	(print x)
 
	(setq tmp x)

	(setq x y)

	(setq y (+ tmp y))

)	

