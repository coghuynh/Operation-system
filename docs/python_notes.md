# Python notes


**Note 1**: Place `*` after `self` in class function when function has default parameter. It makes function demand user specify name of parameters when call function. Prevent parameters misalignment.

```python

 def upsert(
        self,
        *,
        id: str,
        name: str,
        subject_or_object: str = "both",
        description: str = "",
        embedding: Optional[np.ndarray] = None,
        source: str = ""
    ): ...

```