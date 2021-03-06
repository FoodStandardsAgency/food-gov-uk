<?php

class Authorities implements Iterator {

	private $index = 0;
	private $authorities = array();

	/**
	 * Returns the collection of authorities as an array
	 * @return the collection of authorities as an array
	 */
	public function getAll() {
		return $this->authorities;
	}

	public function getForIndex($i) {

		$o = ((0 <= $i) && ($i < count($this->authorities)))
		   ? $this->authorities[$i]
		   : NULL;

		return $o;
	}

	/**
	 * Adds one Authority object to the collection
	 * @param Authority $authoriy The authority
	 * @return $this for method chaining
	 */
	public function addAuthority(Authority &$authority) {
		$position = count($this->authorities);
		$authority->setPosition($position);
		$this->authorities[$position] = $authority;
		return $this;
	}

	/**
	 * Returns <code>TRUE|FALSE</code> whether or not all Authorities belong to the same locality
	 * @return <code>TRUE|FALSE</code> whether or not all Authorities belong to the same locality
	 */
	public function isDistinctLocality() {

		$localities = array();

		// iterate over all authorities and gather their locality
		foreach ($this->authorities as $authority) {
			$localities[$authority->getLocality()] = TRUE;
		}

		return (count($localities) == 1);
	}

	public function count() {
		return count($this->authorities);
	}

	public function current()	{
		return $this->authorities[$this->index];
	}

	public function key() {
		return $this->index;
	}

	public function next() {
		$this->index++;
	}

	public function rewind() {
		$this->index = 0;
	}

	public function valid() {
		return isset($this->authorities[$this->key()]);
	}
}
